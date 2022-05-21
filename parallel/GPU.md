# GPU (graphic processing units)

Le GPU sono pensate per applicare un grande numeri di operazioni su dati indipendenti (SIMD, in realtà SIMT (single instruction multiple threads)).

Nelle GPU (soprattutto per le operazioni grafiche) la larghezza di banda (troughtput) è più importante della latenza ovvero il numero di operazioni eseguibili per unità di tempo è più importante del tempo necessario a completare una singola operazione.

Inoltre alcune operazioni semplici usate molto frequentemente possono essere implementate direttamente via hardware in modo tale da non richiedere diversi cicli di calcolo per eseguire

Nelle GPU la gestione della memoria è completamente manuale, è l'utente a decidere cosa spostare nella DRAM (global memory) della GPU e cosa nella cache (chiamata shared memory: molto piccola per aumentare il bandwidth (~TB/s)).
Ricorda che anche la lettura/scrittura della memoria sulle GPU avviene in parallelo, se i dati sono adiacenti è possibile leggerle tutte insieme

**SIMT:** I singoli cores nelle gpu sono organizzati in gruppi chiamati threads. Singolarmente ogni threads ha una architettura SIMD. Quindi possiamo fare eseguire operazioni diverse su dati diversi ma il numero di operazione è limitato dal numero di threads disponibili (se ne istanziamo più di quanto esistono semplicemente lo scheduler li farà runnare in maniera concorrente ) 

## GPU vs CPU

|                       CPU                        | GPU                                    |
| :----------------------------------------------: | -------------------------------------- |
|       + Memoria grande (sia RAM che cache)       | - Memoria piccola                      |
|           + Grandi frequenze di clock            | - Basse frequenze di clock             |
|          + ALU potente (bassa latenza)           | - Basse performance per singolo thread |
|                - Bassa bandwidth                 | + Alta bandawidth                      |
|             - Basse performance/Watt             | + Alte performance/Watt                |
| - La gestione automatica della cache ha un costo |                                        |

L'idea migliore è quella di usare le CPU per eseguire operazioni sequenziali e GPU per quelle parallele

## Architettura GPU

Tipicamente quando si programma una GPU il workflow è:

1. Copiare i dati sulla GPU
2. Copiare il Kernel (istruzioni)
3. Prendere i risultati e riportarli in RAM

I cores sono organizzati in sottostrutture: principalmente in thread, blocchi e griglie

- I thread sono i core di base. I thread sono dotati di un registro: una piccola memoria che consente di  salvare dati temporanei per consentire il processo di calcolo

- I thread sono organizzati in blocchi. Solo i thread appartenenti allo stesso blocco possono comunicare tra loro (hanno una shared memory tra loro condivisa). Un singolo blocco ha architettura SIMD: posso scegliere quanti thread runnare all'interno di un blocco ma tutti i thread eseguiranno le stesse istruzioni

- Le grid sono insiemi di blocchi. Su grid diverse possono runnare kernel differenti. All'interno della grid è contenuta la global memory condivisa con tutti i blocchi

  Ci sono altri tipi di memorie nella grid:

  - Constant memory: Memoria di sola lettura per i thread con accesso più veloce rispetto alla global memory
  - Texture and Surface memory: Memoria a latenza più bassa per leggere elementi adiacenti di un array

**QUESTA E' LA STRUTTURA DEL SOFTWARE**: I threads vengono eseguiti sui cores, i blocchi sui multiprocessori e le grid sull'intera gpu

| **NB:** Si potrebbe pensare che basta istanziare un numero di thread uguale a quello dei cores per ottenere il massimo delle prestazioni tenendo sempre occupata la GPU ma NON E' così.<br />Esistono nella GPU quelli che si chiamano resident threads ovvero thread che vengono istanziati in attesa di esecuzione ma non eseguiti. Istanziando un numero superiore di thread rispetto a quello dei cores si può sfruttare questi resident cores per ridurre i tempi di latenza dovuti alla copia della memoria tramite concorrenza |
| ------------------------------------------------------------ |

**Problemi:** Il trasferimento di dati sulla global memory della GPU è lento (overhead considerevole) però è possibile copiare i dati e eseguire istruzionio in parallelo.

Conviene usare le GPU solo quando l'overhead della copia in memoria è irrilevante rispetto ai tempi di calcolo. Inoltre conviene usare le GPU solo su alcune istruzioni e tenere il resto su CPU

### Direttive e librerie

Invece che programmare tutto in CUDA potrebbe essere più semplice usare librerie come OpenMP(preferibile per parallelismo su CPU o calcolo distribuito) o OpenACC(preferibile per GPU) dove basta usare delle direttive al preprocessore per mandare istruzioni e dati alla GPU (usato soprattuto su loopcon molte iterazioni e non troppi if). 

Hanno il vantaggio di essere molto semplici da utilizzare ma difficili da debuggare e non efficienti come CUDA (se scritto a modo)

Esistono anche numerose librerie per il calcolo su GPU come thrust o cuBLAS che si occupano autonomamente di eseguire operazioni matematiche complesse gestendo la gpu senza l'intervento manuale dell'utente

## CUDA

| ![image-20220520225730969](images/GPU/image-20220520225730969.png) |
| :----------------------------------------------------------: |
| Variabili builtin di cuda che identificano i thread, blocchi, grid in esecuzione |

Ricorda che tutto ciò all'interno di un kernel non può essere roba proveniente dalla C++ standard library: quando programmi su GPU praticamente devi scrivere nella sintassi e nella logica del C oppure usare altre librerie come thrust (per esempio i std::vector possono essere rimpiazzati dai thrust/device_vector)

Se si vuole passare una classe C++ al kernel tutti i metodi della funzione devono avere una versione \_\_device\_\_

In CUDA ci sono alcune keyword da usare come prefissi alle funzioni che servono a dare istruzioni precise:

- \_\_host\_\_ :il compilatore compila una versione della funzione che funzioni anche su CPU  (necessaria solo se si vuole sia CPu che GPU)
- \_\_device\_\_: la funzione viene compilata per funzionare su GPU (si possono creare anche 2 versioni basta usare \_\_host\_\_  \_\_device\_\_ inline)
- inline: per le funzioni device la compilazione inline è di defult, nel caso volessimo anche la versione host dobbiamo manualmente generarla inline

E' possibile avere anche 2 funzioni totalmente diverse ma con lo stesso nome

- \_\_global\_\_ : questa keyword specifica che la funzione è un kernel da lanciare su gpu. La differenza con la keyword device è che un kernel global è chiamato da CPU e runna su GPU mentre una funzione device è chiamabile solo dalla GPU.
  **I kernel devono essere di tipo void e i suoi argomenti possono essere solo valori scalari o puntatori. Inoltre bisogna passare i dati a valori, non si possono usare le references (è anche logico visto che tutto va copiato sulla global memory della GPU)** (come ho già detto, con i kernel devi ragionare come in C)

Il modo in cui parallelizzare i loop