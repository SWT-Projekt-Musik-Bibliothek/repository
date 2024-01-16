#include "Musikbibliothek.h"
#include <fstream>
//Funktion bekommt neue Meta-Daten
Album Musikbibliothek::album_hinzufuegen(std::string albumname,std::string kuenstlername,Song* songliste,int erscheinungsjahr,int songanzahl,int albumlaenge){
    if (anzahl_alben%10==0){ //falls Albumliste voll ist 
        alben=(Album*)realloc(alben,(anzahl_alben+10)*sizeof(Album)); //neue Albumliste um 10 länger
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
    return album;
}
//Funktion bekommt neue Meta-Daten
Song Musikbibliothek::song_hinzufuegen(std::string songtitel, std::string kuenstlername,int erscheinungsjahr,int songlaenge,std::string genre){
    if (anzahl_songs%100==0){ //falls Songliste voll ist 
        songs=(Song*)realloc(songs,(anzahl_songs+100)*sizeof(Song)); //neue Songliste um 100 länger 
    }
    Song song; //neuer Song mit neuen Meta-Daten
    song.songtitel=songtitel;
    song.kuenstlername=kuenstlername;
    song.erscheinungsjahr=erscheinungsjahr;
    song.songlaenge=songlaenge;
    song.genre=genre;
    songs[anzahl_songs]=song; //fügt den neuen Song in die Songliste hinzu
    anzahl_songs++; //Anzahl der Songs erhöht sich um eins 
    return song;
}
void Musikbibliothek::song_zu_album_hinzufuegen(Album album, Song song){
    if (album.songanzahl%10==0){
        album.songliste=(Song*)realloc(album.songliste,(album.songanzahl+10)*sizeof(Album));
    }
    album.songliste[album.songanzahl]=song;
    album.songanzahl++;
    album.albumlaenge+=song.songlaenge;
}
void Musikbibliothek::song_von_album_entfernen(Album album, Song song){
    bool song_entfernt=true;
    for (int i=0; i<album.songanzahl; i++){
        if (&album.songliste[i]==&song){
            for (int j=i+1; j<album.songanzahl-1; j++){
                album.songliste[j]=album.songliste[j+1];
            }
            album.songanzahl--;
            album.albumlaenge-=song.songlaenge;
            break;
        }
    }
}
//Funktion löscht ein Album
void Musikbibliothek::album_loeschen(Album album){
    //Zuerst wird das Album in der Liste gesucht
    for (int i=0; i<anzahl_alben; i++){
        //Album aus der Liste wird verglichen, ob es gefunden wurde
        if (&(alben[i])==&album){
            //Dann werden alle nachfolgenden Alben in der Liste um einen Platz nach vorne gerückt, um das gelöschte Album zu ersetzen
            for(int j=i+1;j<anzahl_alben-1;j++){
                alben[j]=alben[j+1];
            }
            //Anzahl verringert sich um 1
            anzahl_alben--;
            for (int i=0;i<album.songanzahl;i++){
                Album *null = NULL;
                album.songliste[i].album=*null;
            }
            //Danach wird die Suche beendet
            break;
        }
    }
}
//Funktion löscht ein Album
void Musikbibliothek::song_loeschen(Song song){
    //Zuerst wird der Song in der Liste gesucht
    for (int i=0; i<anzahl_songs; i++){
        //Song aus der Liste wird verglichen, ob er gefunden wurde
        if (&(songs[i])==&song){
            //Dann werden alle nachfolgenden Songs in der Liste um einen Platz nach vorne gerückt, um den gelöschten Song zu ersetzen
            for(int j=i+1;j<anzahl_songs-1;j++){
                songs[j]=songs[j+1];
            }
            //Anzahl verringert sich um 1
            anzahl_songs--;
            song_von_album_entfernen(song.album,song);
            //Danach wird die Suche beendet
            break;
        }
    }
}
//Funktion sucht nach Songs oder Alben
int Musikbibliothek::songs_suchen(Song* suchergebnisse,std::string suchbegriff){
    //Zählt die Suchergebnisse
    int anzahl_ergebnisse=0;
    //Sucht in allen Songs
    for (int i=0; i<anzahl_songs; i++){
        //Vergleicht den Suchbegriff mit dem Songtitel und allen Meta-Daten
        if (songs[i].songtitel.find(suchbegriff)!=std::string::npos||
        songs[i].album.albumname.find(suchbegriff)!=std::string::npos||
        songs[i].kuenstlername.find(suchbegriff)!=std::string::npos||
        std::to_string(songs[i].erscheinungsjahr).find(suchbegriff)!=std::string::npos||
        songs[i].genre.find(suchbegriff)!=std::string::npos){
            //Wenn der Suchbegriff gefunden wurde, füge den Song den Suchergebnissen hinzu
            suchergebnisse[anzahl_ergebnisse]=songs[i];
            anzahl_ergebnisse++;
        }
    }
    //Gibt die Anzahl der Suchergebnisse für die Suchergebnisse (Call by Reference) zurück
    return anzahl_ergebnisse;
}
int Musikbibliothek::alben_suchen(Album* suchergebnisse,std::string suchbegriff){
    //Zählt die Suchergebnisse
    int anzahl_ergebnisse=0;
    //Sucht in allen Alben
    for (int i=0; i<anzahl_alben; i++){
        //Vergleicht den Suchbegriff mit dem Albumnamen und allen Meta-Daten
        if (alben[i].albumname.find(suchbegriff)!=std::string::npos||
        alben[i].kuenstlername.find(suchbegriff)!=std::string::npos||
        std::to_string(alben[i].erscheinungsjahr).find(suchbegriff)!=std::string::npos){
        //Wenn der Suchbegriff gefunden wurde, füge das Album den Suchergebnissen hinzu
            suchergebnisse[anzahl_ergebnisse]=alben[i];
            anzahl_ergebnisse++;
        }
    }
    //Gibt die Anzahl der Suchergebnisse für die Suchergebnisse (Call by Reference) zurück
    return anzahl_ergebnisse;
}
bool Musikbibliothek::bibliothek_speichern(std::string dateipfad){
    std::ofstream bibliothek(dateipfad);
    if (bibliothek.is_open()){
        for(int i=0; i<anzahl_songs; i++){
            bibliothek<<("song;"+std::to_string(i)+songs[i].to_string_csv()+";");
        }
        for (int i=0; i<anzahl_alben; i++){
            std::string songnummern="";
            for (int j=0;j<alben[i].songanzahl;j++){
                for (int k=0;k<anzahl_songs;k++){
                    if (&(songs[k])==&(alben[i].songliste[j])){
                        songnummern+=std::to_string(k)+";";
                    }
                }
            }
            bibliothek<<("album;"+std::to_string(i)+alben[i].to_string_csv()+";"+songnummern+";");
        }
        bibliothek.close();
        return true;
    }
    return false;
}
void Musikbibliothek::bibliothek_leeren(){
    free(alben);
    alben=(Album*) malloc(10*sizeof(Album));
    anzahl_alben=0;
    free(songs);
    songs=(Song*) malloc(100*sizeof(Song));
    anzahl_songs=0;
}
bool Musikbibliothek::bibliothek_laden(std::string dateipfad){
    bibliothek_leeren();
    std::ifstream bibliothek(dateipfad);
    if (bibliothek.is_open()) {
        std::string zeile;
        while (std::getline(bibliothek, zeile)) {
            if (zeile.substr(0,4)=="song"){
                int songtitel_ende=zeile.find(';',6);
                std::string songtitel=zeile.substr(6,songtitel_ende-6);
                int kuenstlername_ende=zeile.find(';',songtitel_ende+1);
                std::string kuenstlername=zeile.substr(songtitel_ende+1,kuenstlername_ende-songtitel_ende-1);
                int erscheinungsjahr_ende=zeile.find(';',kuenstlername_ende+1);
                int erscheinungsjahr=std::stoi(zeile.substr(kuenstlername_ende+1,erscheinungsjahr_ende-kuenstlername_ende-1));
                int songlaenge_ende=zeile.find(';',erscheinungsjahr_ende+1);
                int songlaenge=std::stoi(zeile.substr(erscheinungsjahr_ende+1,songlaenge_ende-erscheinungsjahr_ende-1));
                int genre_ende=zeile.find(';',songlaenge_ende+1);
                std::string genre=zeile.substr(songlaenge_ende+1,genre_ende-songlaenge_ende-1);
                song_hinzufuegen(songtitel,kuenstlername,erscheinungsjahr,songlaenge,genre);
            }
            if (zeile.substr(0,5)=="album"){
                int albumname_ende=zeile.find(';',6);
                std::string albumname=zeile.substr(6,albumname_ende-6);
                int kuenstlername_ende=zeile.find(';',albumname_ende+1);
                std::string kuenstlername=zeile.substr(albumname_ende+1,kuenstlername_ende-albumname_ende-1);
                int erscheinungsjahr_ende=zeile.find(';',kuenstlername_ende+1);
                int erscheinungsjahr=std::stoi(zeile.substr(kuenstlername_ende+1,erscheinungsjahr_ende-kuenstlername_ende-1));
                int songanzahl_ende=zeile.find(';',erscheinungsjahr_ende+1);
                int songanzahl=std::stoi(zeile.substr(erscheinungsjahr_ende+1,songanzahl_ende-erscheinungsjahr_ende-1));
                Song* songliste=(Song*) malloc(songanzahl*sizeof(Song));
                int albumlaenge_ende=zeile.find(';',songanzahl_ende+1);
                int albumlaenge=std::stoi(zeile.substr(songanzahl_ende+1,albumlaenge_ende-songanzahl_ende-1));
                int songnummer_anfang=albumlaenge_ende+1;
                Album album=album_hinzufuegen(albumname, kuenstlername, songliste, erscheinungsjahr, songanzahl, albumlaenge);
                for (int i=0;i<songanzahl;i++){
                    int songnummer_ende=zeile.find(';',songnummer_anfang+1);
                    int songnummer=std::stoi(zeile.substr(songnummer_anfang,songnummer_ende-songnummer_anfang));
                    songliste[i]=songs[songnummer];
                    songs[songnummer].album=album;
                }
            }
        }
        bibliothek.close();
        return true;
    }
    return false;
}