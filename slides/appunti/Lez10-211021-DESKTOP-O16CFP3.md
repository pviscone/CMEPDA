# Lez 10 21/10/21 : Inizio programmazione parallela 

(Quasi tutto preso da wikipedia, dove sono state usate altri fonti è specificato)



## Architettura di  Von Neumann

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

La località dipente fortemente dall’applicazione. In alcuni casi c’è località di un solo tipo

Basandosi sul principio di località la memoria è basata secondo una gerarchia:

1. Registri: memoria facente parte della CPU in cui vengono effettuate le operazioni aritmetiche

2. L1 Cache: presente sullo stesso chip del processore, memoria SRAM (flip flop latch, da 4 a 6 transistor per bit). Può essere sia unificata che separata per dati e istruzioni. I trasferimenti dalle memorie inferiori sono totalmente gestiti dall’hardware

3. L2 ed L3 Cache: memoria SRAM, come L1 cache ma più grande in memoria a scapito della velocità

4. Memoria RAM: memoria DRAM (occorre un circuito che riscriva periodicamente il contenuto della cella di memoria poichè il condensatore mantiene la carica solo per un tempo definito, 1 transistor a bit).

   Il trasferimento alle memorie di libello inferiore sono gestiti dal software

5. Hard Drive e altre mememoria di storage

Il principio di funzionamento di queste memorie è che ogni livello superiore della gerarchia contiene un sottoinsieme dei livelli inferiori e **il processore accede solo al livello L1**

Le informazioni vengono di volta in volta copiate tra livelli adiacenti sfruttando i principi di località e ogni volta che il processore cerca un blocco di memoria nella L1 e non lo trova il blocco viene copiato nella L1 dai livelli inferiori. L’obiettivo è massimizzare il rate di HIT (presenza del blocco nella L1). Ci sono varie tecniche ma PACE, non mi serve

## Tassionomia di Flynn



