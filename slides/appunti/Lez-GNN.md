# Graph Neural Network

 Tutti i tipi di reti neurali sono utili principalmente in task di regressione o classificazione (task supervisionati).

Uno dei modelli che ha avuto più successo è la CNN sulle immagini che permette di estrarre feature locali da esse (usate per la rivelazione di GW, rivelazione di neutrini, riconoscimento di esopianeti,etc.).

Un altro modello che ha avuto successo è quello delle RNN, utile per monitorare serie temporali e per la ricerca per segnali transienti (Utile per detection di supernove, per il monitoraggio dei magneti di LHC, per la classificazione di eventi a LHC, triggering, etc.)

**Problema**: Molto spesso si ha a che fare con dati molto irregolari che non possono essere rappresentati come sequenze

Esempi tipici sono:

- Sensori di un detector (geometria estremamente irregolare)
- Strutture molecolari
- Galassie/ popolazione stellare

Volendo questo tipo di dati si può rappresentare con delle matrici ma quello che si ottiene sono delle matrici estremamente sparse che rendono totalmente inefficace l'approccio delle CNN

Una scrittura più compatta può essere creare una "tabella" con le coordinate della matrice non nulle e relativo valore. In questo modo però si perde la località dei dati

## GNN

Vogliamo generalizzare il concetto di neural network e continuare a sfruttare la località dei dati.

Creiamo una struttura in cui:

- ogni dato rappresenta il nodo di un grafo e i dati sono connessi da degli edges E **direzionali** (possono essere anche simmetrici)

  (Se sono presenti vertici di diverso tipo solitamente si connettono solo vertici dello stesso tipo tra loro.)

- un grafo può essere fully connected (N^2 connessioni) oppure si può usare un qualche criterio (es. knn) per ridurre numero connessioni

- Un grafo è rappresentato dalla coppia (V,E). Se non si hanno informazioni a priori sui dati solitamente si usa un grafo fully connected

Il principio di funzionamento è:

- Le GNN sono architetture basate su una rappresentazione astratta dei dati.

-  Ogni esempio in un dataset è rappresentato da un set di vertici e ogni vertice è immerso in un grafo come un vettore di features (se numero di feature diverso tra i vertici va fatto zero padding)

- I vertici sono connessi tra loro tramite gli edges

- I "messaggi" sono passati tramite le connesione e aggregati nei vertici. La funzione che passa i dati da vertice a vertice è o settata a priori o imparata con una rete neurale convenzionale

  INSERISCI IMMAGINE

- Ogni vertice ha una funzione di aggregazione che ha il ruolo di mettere insieme tutte le informazioni provenienti dagli altri vertici (ha lo stesso ruolo del pooling nelle CNN o del net nelle Dense NN)

- La nuova rappresentazione di ogni nodo è creato basato sull'informazione acquisita da tutto il grafo.

- Spesso si salva l'informazione acquisita "appesa" all'informazione originale e poi si può combinare tramite una apposiata funzione con l'informazione principale. Queste poi possono essere processate con una NN convenzionale

Una volta che è stata creata la nuova rappresentazione di ogni vertice possiamo



EH????  Risenti tutto con calma e cerca referenze (vedi quelle presenti nelle slides)

