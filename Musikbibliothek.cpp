#include "album.h"
#include "song.h"
Album* alben;
int anzahl_alben=0;
Song* songs;
int anzahl_songs=0;
//Funktion bekommt neue Meta-Daten
void album_hinzufuegen(std::string albumname,std::string kuenstlername,Song *songliste,int erscheinungsjahr,int songanzahl,int albumlaenge){
    if (anzahl_alben%10==0){ //falls Albumliste voll ist 
        Album* neu_alben=(Album*) malloc((anzahl_alben+10)*sizeof(Album)); //neue Albumliste um 10 länger
        for(int i=0; i<anzahl_alben; i++){ 
            neu_alben[i]=alben[i]; //kopiert alte Albumliste in die neue 
        }
        free(alben); //Löscht alte Albumliste 
        alben=neu_alben; // schiebt die neue in die alte 
    }
    Album album; //neues Album mit neuen Meta-Daten
    album.albumname=albumname;
    album.kuenstlername=kuenstlername;
    album.songliste=songliste;
    album.erscheinungsjahr=erscheinungsjahr;
    album.songanzahl=songanzahl;
    album.albumlaenge=albumlaenge;
    alben[anzahl_alben]=album; //fügt das neue Album in die Albumliste hinzu
    anzahl_alben++; //Anzahl der Alben erhöht sich um eins 
}


