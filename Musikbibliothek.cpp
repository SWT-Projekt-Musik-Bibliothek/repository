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
//Funktion bekommt neue Meta-Daten
void song_hinzufuegen(std::string songtitel, Album album,std::string kuenstlername,int erscheinungsjahr,int songlaenge,std::string genre){
    if (anzahl_songs%100==0){ //falls Songliste voll ist 
        Song* neue_songs=(Song*) malloc((anzahl_songs+100)*sizeof(Song)); //neue Songliste um 100 länger
        for(int i=0; i<anzahl_songs; i++){ 
            neue_songs[i]=songs[i]; //kopiert alte Songliste in die neue 
        }
        free(songs); //Löscht alte Songliste 
        songs=neue_songs; // schiebt die neue in die alte 
    }
    Song song; //neuer Song mit neuen Meta-Daten
    song.songtitel=songtitel;
    song.album=album;
    song.kuenstlername=kuenstlername;
    song.erscheinungsjahr=erscheinungsjahr;
    song.songlaenge=songlaenge;
    song.genre=genre;
    songs[anzahl_songs]=song; //fügt den neuen Song in die Songliste hinzu
    anzahl_songs++; //Anzahl der Songs erhöht sich um eins 
}


