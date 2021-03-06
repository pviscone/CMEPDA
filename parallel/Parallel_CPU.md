# Lez 10 21/10/21 : Inizio programmazione parallela 

(Quasi tutto preso da wikipedia, dove sono state usate altri fonti è specificato)

# Architettura di  Von Neumann

E’ l’architettura hardware dei computer moderni. 

Lo schema si basa su 5 componenti:

- CPU: unità di elaborazione che si divide in:
  - ALU: Unità logica e aritmetica. E’ un circuito logico che recupera i dati dai registri del processore, processa i dati nell’accumulatore (un altro registro che fa da ponte tra l’input e l’output) e salva il risultato nel registro di uscita
  - Unità di controllo: E’ l’unitò che gestisce le operazioni dell’ALU. L’unità di controllo riceve in input ad ogni ciclo di clock il clock stesso (per sincronizzare le operazioni), l’istruzione, i segnali di flag che danno indicazione alla ALU sullo stato della cpu e segnali dal bus di controllo che riguardano lo stato di dispositivi esterni
  - Altri registri come il registro dei dati, degli indirizzi, di istruzione corrente (contiene l’indirizzo di memoria dell’istruzione in esecuzione), dell’istruzione successiva,etc.
- Memoria volatile: la RAM. Vengono copiati i programmi che la CPU deve eseguire e i dati che deve processare (memoria condivisa tra dati e programmi)
- Unità I/O: due unità che si occupano di interfacciarsi con le periferiche esterne
- BUS: canale di comunicazione che collega tutte le componenti tra loro

Questa architettura però ha un **bottleneck**: il fatto di dover condividere un unico bus fa si che per completare una istruzione siano necessari 2 accessi in memoria poichè dati e istruzioni condividono la stessa memoria.

Questo crea enormi difficoltà nel parallelismo. Ci sono diversi modi per risolvere il problema:

- Creazione di 2 bus separati per istruzioni e dati (Architettura di Harvard, usata sui processori RISC con set di istruzioni ridotto). In questo modo si può accedere ai due elementi contemporaneamente MA necessita di maggiori risorse (più memoria e più connessioni)
- Branch prediction:  Componente aggiuntiva della cpu che cerca di prevedere l’esito di un’operazione su cui si basa l’accettazione di una istruzione di salto condizionato (essenzialmente un’alternativa). 
- Caching e gerarchia della memoria

## Gerarchia della memoria

**Fonte**: http://www.ce.uniroma2.it/courses/ce1920/slides/GerarchiaMemoria.pdf

La memoria RAM ha velocità di accesso molto minori rispetto ai tempi caratteristici con cui lavora la CPU e tecnicamente si riescono a fare memorie veloci solo di basse dimensioni (e ad alto costo). La soluzione è creare una gerarchia.

Si possono organizzare in memoria i programmi e i dati in modo da sfruttare al massimo il **principio di località**:

- I programmi riutilizzano dati e istruzioni utilizzati di recente (località temporale)
- Elementi i cui indirizzi di memoria sono vicini tendono ad essere referenziati in tempi ravvicinati (località temporale)

La località dipende fortemente dall’applicazione. In alcuni casi c’è località di un solo tipo

Basandosi sul principio di località la memoria è basata secondo una gerarchia:

1. Registri: memoria facente parte della CPU in cui vengono effettuate le operazioni aritmetiche

2. L1 Cache: presente sullo stesso chip del processore, memoria SRAM (flip flop latch, da 4 a 6 transistor per bit). Può essere sia unificata che separata per dati e istruzioni. I trasferimenti dalle memorie inferiori sono totalmente gestiti dall’hardware

3. L2 ed L3 Cache: memoria SRAM, come L1 cache ma più grande in memoria a scapito della velocità

4. Memoria RAM: memoria DRAM (occorre un circuito che riscriva periodicamente il contenuto della cella di memoria poichè il condensatore mantiene la carica solo per un tempo definito, 1 transistor a bit).

   Il trasferimento alle memorie di libello inferiore sono gestiti dal software

5. Hard Drive e altre mememoria di storage

Il principio di funzionamento di queste memorie è che ogni livello superiore della gerarchia contiene un sottoinsieme dei livelli inferiori e **il processore accede solo al livello L1**

Le informazioni vengono di volta in volta copiate tra livelli adiacenti sfruttando i principi di località e ogni volta che il processore cerca un blocco di memoria nella L1 e non lo trova il blocco viene copiato nella L1 dai livelli inferiori. L’obiettivo è massimizzare il rate di HIT (presenza del blocco nella L1). Ci sono varie tecniche ma PACE, non mi serve

## Legge di moore e Dennard scaling

https://wgropp.cs.illinois.edu/courses/cs598-s15/lectures/lecture15.pdf

**Legge di Moore**: Il numero di transistor nei microprocessori per unità di area raddoppia ogni 2 anni (ovvero le loro dimensioni dimezzano)

Questa legge inizia a scricchiolare a causa di limiti fisici ma in ogni caso, anche se finora è stata valida, non bisogna confondere l'aumento di transistor con l'aumento di performance anche se per molto tempo le performance e il numero di transistor sono stati strettamente correlati tra loro in modo lineare

**Dennard scaling**: La potenza assorbita da un transistor è $P=CV^2 f$ dove f è la frequenza, V il voltaggio e C la capacità che è proporzionale all'area. Quindi a potenza fissata, man mano che i transistor sono diventati più piccoli, i circuiti hanno potuto operare a voltaggi minori (V= campo* lunghezza) e frequenze più alte

Il problema è che il dennard scaling ignora il voltaggio di threshold e la corrente di leakage dei transistor quindi si arriva un punto in cui per aumentare la frequenza bisogna necessariamente aumentare anche la potenza assorbita (e di conseguenza una serie di problematiche connesse)

Questo è il motivo principale per cui è da anni che la velocità di clock delle CPU non subisce incrementi e le aziende di CPU hanno iniziato a focalizzarsi sul multicore per incrementare le prestazioni. 

Finchè il Dennard scaling è stato valido  (circa fino il 2006) si ha avuto un raddoppiamento delle prestazioni ogni anno e mezzo (Legge di Koomey)

## Pipelining

http://math.unife.it/informatica/insegnamenti/architettura-elaboratori-laboratorio/materiale-architettura/20130515-mips-pipeline.pdf

https://nigno17.github.io/assets/pdf/Pipelining.pdf

Il pipelining è una tecnica per migliorare le prestazioni del processore basata sulla **sovrapposizione dell'esecuzione di più istruzioni appartenti a un flusso sequenziale**. Questa tecnica è implementata in tutti i processori moderni

![Sequential-Execution-of-Instructions](./images/Parallel_CPU/Sequential-Execution-of-Instructions.jpg)



![Instruction-Pipelining](./images/Parallel_CPU/Instruction-Pipelining.jpg)

La presenza di pipeline aumenta il numero di istruzioni eseguite per unità di tempo MA non riduce la il tempo di esecuzione della singola istruzione. 

L'esecuzione di un'istruzione richiede 5 cicli di clock e (nel caso di cache hit per semplicità) si suddivide in:

1. Prelievo dalla memoria
2. Decodifica
3. Elaborazione
4. Attivazione della memoria
5. Scrittura sui registri

Nel caso migliore (senza cache miss) si hanno 5 istruzioni che runnano in parallelo. Per gestire l'esecuzione in pipeline di più istruzioni è necessario mantenere delle informazioni tra i vari stadi nei **buffer interstadi** che contengono vari registri per la gestione della pipeline

![pipeline_buffer](./images/Parallel_CPU/pipeline_buffer.PNG)

Il pipeline però ha dei **problemi**:

- **Dipendenze di dato** : avviene quando una istruzione ha bisogno di leggere dai registri l'output dell'istruzione precedente![data_dependency](./images/Parallel_CPU/data_dependency.PNG)

  Per porre in stallo un'istruzione vengono inserite tra le istruzioni in conflitto delle istruzioni nulle che causano un ciclo di inattività. Per far si che questo accada il meno possibile i compilatori ottimizzani riordinano il codice in modo tale da spostare istruzioni utili là dove andrebbero delle istruzioni nulle.

  Per risolvere il problema è possibile fare **operand forwarding** ovvero creare un'architettura in cui i registri intersadio  vengono inoltrati agli stadi precedenti

  ![operand_forwarding](./images/Parallel_CPU/operand_forwarding.PNG)

  

- **Ritardi nella memoria** : Nei casi di cache miss si possono avere ritardi anche di più di 10 cicli di clock nell'accesso alla memoria. In questi casi tutte le istruzioni successive dovranno essere ritardate 

- **Ritardi nei salti**: nel caso di un'istruzione di salto (vai a un'altra istruzione), l'indirizzo di destinazione viene caricato durante il terzo ciclo di clock. Questo significa che due cicli di clock vengono persi (**penalità di salto**)

  ![salto](./images/Parallel_CPU/salto.PNG)

  Per evitare che questo accada si può aggiungere un buffer di destinazione di salto che contiene una tabella di tutte le istruzioni di salto del programa con annessi indirizzi di destinazione. In questo modo la predizione della destinazione di salto avviene nel primo stadio ovvero durante la lettura della memoria

- **Limiti di risorse** : La pipeline può andare in stallo quando una risorsa hardware è richiesta da più istruzioni contemporaneamente. Per evitare il provlema si possono avere cache separate per istruzioni e dati

Per valutare l'incremento delle prestazioni bisogna considerare tutte le occorrenze delle problematiche sopra elencate. Tipicamente il pipeliningg causa un **incremento delle prestazioni circa di un fattore 2** mentre nel caso ottimale sarebbe un fattore 5 (1 istruzione per ciclo di clock)

### Processori superscalari

Sono processori con più unità di esecuzione che eseguono in parallelo più istruzioni. sono formati dai seguenti componenti e buffer:

- Unità di prelievo e coda di istruzioni
- Unità di smistamento e stazioni prenotazioen 
- Unità di esecuzione e registri temporanei
- Unità di commitment e buffer di riordino

In questo modo è possibile eseguire più istruzioni (quante sono le unità di esecuzione) contemporaneamente oltre a usare il pipelining

![superscalar](./images/Parallel_CPU/superscalar.PNG)*Caso in cui si hanno 2 unità di esecuzione*

Durante lo smistamento il processore deve assicurarsi che tutte le risorse necessarie siano disponibili e deve prevenire i deadlock (casi di stallo a causa di dipendeze reciproche di due istruzioni)

I processori superscalari soffrono delle stesse problematiche del pipelinig ma tutti i problemi che possono causare stalli hanno un rate che è crescente con le unità di esecuzione

# Concorrenza

WIKIPEDIA

https://sceweb.uhcl.edu/helm/RationalUnifiedProcess/process/workflow/ana_desi/co_cncry.htm

Un sistema si dice conorrente se può avere più azioni **in progresso** di esecuzione allo stesso tempo (a livello intuitivo le operazioni vengono usate in maniera alternata dando l'impressione di essere eseguite contemporaneamente)

**Problematiche**:

- Race conditions: Nel caso in cui diversi processi condividano una risorsa comune il risultato dell'esecuzione di più processi dipende dall'ordine in cui vengono eseguiti. Per risolvere il problema serve una regola di mutua esclusione

- Deadlock: Avviene quando un insieme di processi attendono l'esecuzione degli altri processi dell'insiemeentrando in un ciclo di attesa (stallo). Avviene soprattutto se ad un processo viene garantito l'accesso esclusivo ad una risorsa.  Per risolvere gli stalli si possono usare principalmente 3 tecniche:

  - prerilascio: Viene eliminato il diritto di accesso esclusivo a un processo (abbastanza difficile da fare)
  - punto di controllo: Vengono creati dei checkpoint dei registri ai quali accedere ogni volta che si crea uno stallo (potrebbe portare a perdite di informazione)
  - eliminazione: Termina processi finchè lo stallo non si risolve

  In ogni caso esistono una serie di algoritmi per evitare gli stalli durante la fase di allocazione delle risorse

- Starvation: Quando un processo ha minore priorità di accesso a una risorsa rispetto a un altra rimane bloccato e non può proseguire nonostante non sia in stallo. L'unico modo per risolvere questo problema è stabilire delle politiche di priorità eque

*Definizioni* :

- **Processo**: Entità dinamica caricata in RAM generata da un programma (codice statico). E' una sequenza di attività (task) controllata da un programma (scheduler) che si svolge su un processore sotto la supervisione del sistema operativo che gli assegna le risorse necessarie per l'esecuzione di un programma tranne la cpu.

  - *Processi diversi usano diverse aree di memoria*
  - *La creazione di un nuovo processo è onerosa per il sistema in quanto deve allocare le risorse necessarie alla sua esecuzione*

- **Thread**: Sottoprocesso (in realtà è un percorso di esecuzione di un processo ovvero una procedura interna istanziata dal sistema operativo) a cui è assegnata la CPU per l'esecuzione. I thread possono essere eseguiti in maniera concorrente indipentdentemente dallo stato del processo. La sua creazione ha un overhead minore di quella di un processo in quanto non sono necessarie tutte le allocazioni che necessitano i processi (Il thread ha uno stack tutto suo ma l'area dati globale è condivisa con gli altri thread)

  - *I Thread condividono le stesse informazioni di stato, la stessa memoria e le stesse risorse di sistema*

  - *La sua attivazione avviene in tempi ridotti in quanto tutte le risorse sono già disponibili dalla creazione del processo*

    

Ci sono diversi tipi di concorrenza:

- **Multiprocessing**: Avviene su CPU multiple. Diversi task vengono assegnati dinamicamente a diversi processori (i thread vengono assegnati dinamicamente alle cpu)

- **Multitasking**: Avviene su una singola CPU 

  Nel multitasking un processo può avre 3 stati:

  - blocked: in attesa di un input o di allocazione risorse
  - ready: in attesa dell' approvazione del sistema operativo per l'esecuzione
  - running: in esecuzione

  I sistemi multitasking condividono un unico thread di esecuzione tra tutti i loro processi. In questo modo il sistema può trasferire il controllo della cpu da un processo all'altro al verificarsi di un interuzione (attesa di un input/output,etc.)

  Lo switch del processo ha un overhead considerevole anche a causa del fatto che diversi processi possiedono indirizzi in memoria diversi e in quanto il thread in esecuzione viene temporaneamente interrotto e un altro inizia o riprende da dove si era interrotto

- **Multithreading**: I thread di un processing vengono runnati in maniera concorrente su ogni cpu

## Sincronizzazione

Per gestire possibili situazioni di accesso a memorie condivise è necessaria una comunicazione  tra i vari processi. Le più comune vie di comunicazioni interprocessuali sono:

- **Mutex**: variabili binarie che permettono di gestire l'accesso ad una risorsa  condivisa mediante accesso esclusivo di uno dei contendenti

- **[Semafori](https://it.wikipedia.org/wiki/Semaforo_(informatica)) n-ari**: variabili n-arie che possono essere incrementate e decrementate. Il  processo che decrementa il semaforo si bloccherà appena raggiunto lo  zero della variabile. Un processo che incrementa il semaforo invece  risveglia tutti i processi che si erano bloccati in fase di decremento.

- **Variabili di tipo condizione**: variabili con associate due primitive: *wait* (aspetta) e *signal* (segnala, risveglia). Una procedura che richiama la primitiva wait si  pone in attesa indefinita, una procedura che richiama la primitiva  signal ne risveglia una in attesa su wait

- **Scambio di messaggi**: due procedure, send (invia) e  receive (ricevi), permettono a due processi di scambiarsi messaggi. solitamente usato in sistemi paralleli.

- **Barriere**: un processo che ha terminato la sua fase chiama una primitiva *barrier* e si blocca. Quando tutti i processi coinvolti hanno terminato il loro stadio di esecuzione invocando anch'essi la primitiva *barrier*, il sistema li sblocca tutti permettendo di passare ad uno stadio successivo.

## multithreading vs multiprocessing

https://www.guru99.com/difference-between-multiprocessing-and-multithreading.html

**Multiprocessing**:

- **Vantaggi**: 
  - incremento delle prestazioni tramite l'utilizzo di più cpu
  - non necessita di sincronizzazione per l'utilizzo delle risorse
  - i processi sono killabili
- **Svantaggi**:
  - Ha un overhead di memoria considerevole
  - La comunicazione tra più processi è complicata e porta overhead aggiuntivo

**Multithreading**:

- **Vantaggi**:

  - Condividono lo stesso spazio di memoria
  - Il costo di comunicazione tra i threa è basso
  - Ideali per operazioni legate all' I/O
  - tempo di avvio e di switch dei thread molto più basso rispetto ai processi

  **Svantaggi**:

  - I thread NON sono killabili
  - Implementazione più complicata e rischio di race conditions molto alto
  - Necessita di sincronizzazione manuale

# Parallelismo e Tassonomia di Flynn

https://www.geekboots.com/story/parallel-computing-and-its-advantage-and-disadvantage

**Parallelismo**: Esecuzione simultanea di diverse operazioni 

- **Vantaggi**:
  - Incremento delle prestazioni molto alto 
  - I singoli componenti di un' architettura parallela sono tipicamente componenti semplici ed economici
  - Incremento del rapporto Performance/Costo
- **Svantaggi**:
  - Non sempre è possibile parallelizzare un algoritmo
  - Overhead dato dal trasferimento di dati, comunicazione (tra i processi), sincronizzazione (se la memoria è condivisa bisogna implementare un alogica di lock-unlock della memoria che causa una latenza aggiuntiva), etc.
  - Alto consumo di corrente
  - Difficile da implementare, testare e da debbugare
  - Performano peggio sulla parte di codice seriale
  - Il tempo di esecuzione tra i vari task deve essere simile altrimenti il tempo per ogni operazione è dominato dal task più lento. Serve un buon bilanciamento



http://tesi.cab.unipd.it/26364/1/Tesi_Lorenzo_Baesso_578440.pdf

Una architettura parallela è caratterizzata da 3 livelli di parallelismo:

- Data level parallelism: dati vengono ditribuiti ed elaborati contemporaneamente da più processori
- Instruction level parallelism: istruzioni vengono distribuite ed eseguite contemporaneamnete da più processori
- Thread level parallelism: thread/processi eseguiti in parallelo da più processori (non necessariamente in modo sincrono) 

In questo modo si possono classificare in 4 classi tutte le architetture parallele:

- **SISD: single instruction single data** : L'architettura di Von Neumann discussa ne è un esempio. Non contengono alcun elemento di parallelismo, funzionano in modo sequenziale

- **MISD Multiple instruction single data**: n processori condividono un'unica unità di memoria . Ad ogni ciclo di clockil dato viene elaborato dalle cpu in parallelo simultaneamente, ciascuno secondo le istruzioni ricevute dalla propria unità di controllo. Utile per fare diverse operazioni sugli stessi dati. Tipologia particolare, usata per lo più in ambito di crittografia 

- **SIMD single istruction multiple data**: composto da n processori identici, ognuno dotato di una propria memoria locale. Tutti i processori lavorano sotto lo stesso medesimo flusso di istruzioni unico, eseguono contemporaneamente la stessa istruzione ma su dati diversi.

  Gli lgoritmi su questa architettura sono facili da implementare ma bisogna poter suddividere i problemi in una serie di sottoproblemi identici.

  Il tipo di processore più cpmune di questa classe è il **processore vettoriale** , un processora che implementa dei registri per la vettorizzazione (SSE/AVX)

- **MIMD multiple instruction multiple data**: Classe più generale. Ha n processori, n flussi di istruzioni e n flussi di dati. Ogni processore possiede una propria memoria locale e una propria unità di controllo. Possono eseguire contemporanemente istruzioni diverse su dati diversi, in questo modo si raggiunge il parallelismo a livello di thread/processi (solitamente operano in modo asinctrono). La sincornizzazione però è un problema in quanto p molto difficile implementare e progettare algoritmi asincroni

# Valutazione delle prestazioni

http://tesi.cab.unipd.it/26364/1/Tesi_Lorenzo_Baesso_578440.pdf

## Legge di Amdahl

Definito lo speed up come il rapporto di tempo di esecuzione tra la versione parallela e sequenziale di un algoritmo, la legge di amdahl afferma che lo speed up ottenibile è $$S=/frac{1}{1-P+P/N}$$ dove P è la frazione di codice parallelizabile e N il numero di processori

![amdahl](./images/Parallel_CPU/amdahl.PNG)

Purtroppo ci saranno sempre delle parti di codici da eseguire necessariamente in maniera sequenziale.

Teoricamente a questa legge, al denomiatore, andrebbe aggiunto un fattore di overhead di gestione degli n thread o processi

**Limiti della legge di amdahl**:

- i sistemi multicore hanno molteplici cache e abbassano la latenza della memoria
- Alcuni algoritmi hanno formulazioni parallele migliori con un minor numero di passi comutazionale
- Assume che il problema rimanga di dimensione costante mentre in genere aumenta con l'aumentare delle risorse e ciò che rimane costante è il tempo di esecuzione (???  non ho capito)

## Legge di Gustafson

Afferma che i problemi con grandi e ripetitivi gruppi di dati possono essere efficacemente parallelizzati. 

Afferma che $S=N-(1-P)(N-1$) 

Questa legge affronta i deficit della legge di amdahl che non considera che all'aumentare del numero di macchine aumenta anche  la potenza di calcolo disponibili  

![gustafson](./images/Parallel_CPU/gustafson.PNG)

![gustafsonvsamdahl](./images/Parallel_CPU/gustafsonvsamdahl.PNG)

