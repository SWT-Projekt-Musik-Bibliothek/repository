#include "cli.h"
#include<iostream>
std::string texteingabe(std::string aufforderung){
    std::cout<<aufforderung;
    std::string eingabe;
    std::cin>>eingabe;
    return eingabe;
}
int zahleingabe(std::string aufforderung){
    int zahl;
    bool eingabe_ist_zahl;
    do{
        eingabe_ist_zahl=true;
        std::string eingabe=texteingabe(aufforderung);
        for (int i=0;i<eingabe.length();i++){
            if (!isdigit(eingabe[i])){
                eingabe_ist_zahl=false;
            }
        }
        if(eingabe_ist_zahl){
            zahl=stoi(eingabe);
        }
        else{
            std::cout<<"Ungültige Eingabe: Die Eingabe muss eine reine Zahl ohne Vorzeichen und Komma sein!\n";
        }
    }while(!eingabe_ist_zahl);
    return zahl;
}
void bibliothek_einlesen(){
    bool bibliothek_geladen=false;
    while(!bibliothek_geladen){
        std::string speicherort=texteingabe("Bitte geben Sie den Dateipfad der existierenden Bibliothek ein.\n");
        if(speicherort.substr(speicherort.length()-4,speicherort.length()-1)==".CSV"){
            bibliothek_geladen=bibliothek_laden(speicherort);
            if (!bibliothek_geladen){
                std::cout<<"Dies ist kein Dateipfad einer Musikbibliothek!\n";
            }
        }
        else{
            std::cout<<"Der eingegebene Dateipfad muss mit '.csv' enden!\n";
        }
    }
}
void bibliothek_abspeichern(){
    bool bibliothek_geladen=false;
    while(!bibliothek_geladen){
        std::string speicherort=texteingabe("Bitte geben Sie den Dateipfad ein, an dem die Bibliothek gespeichert werden soll.\n");
        if(speicherort.substr(speicherort.length()-4,speicherort.length()-1)==".CSV"){
            bibliothek_geladen=bibliothek_laden(speicherort);
            if (!bibliothek_geladen){
                std::cout<<"Bei diesem Dateipfad kann die Bibiothek nicht gespeichert werden!\n";
            }
        }
        else{
            std::cout<<"Der eingegebene Dateipfad muss mit '.csv' enden!\n";
        }
    }
}
void song_eingeben(){
    std::string songtitel=texteingabe("Bitte geben Sie den Titel des Songs ein.\n");
    std::string kuenstlername=texteingabe("Bitte geben Sie den Künstlernamen des Songs ein.\n");
    int erscheinungsjahr=zahleingabe("Bitte geben Sie das Erscheinungsjahr des Songs ein.\n");
    int songlaenge=zahleingabe("Bitte geben Sie die Songlänge ein.\n");
    std::string genre=texteingabe("Bitte geben Sie das Genre des Songs ein.\n");
    song_hinzufuegen(songtitel, kuenstlername, erscheinungsjahr, songlaenge, genre);
}
void album_eingeben(){
    std::string albumname=texteingabe("Bitte geben Sie den Namen des Albums ein.\n");
    std::string kuenstlername=texteingabe("Bitte geben Sie den Künstlernamen des Albums ein.\n");
    int erscheinungsjahr=zahleingabe("Bitte geben Sie das Erscheinungsjahr des Albums ein.\n");
    Song* songliste=(Song*) malloc(10*sizeof(Song));
    album_hinzufuegen(albumname, kuenstlername, songliste, erscheinungsjahr, 0, 0);
}
void songtitel_bearbeiten(Song song){
    std::string neuer_songtitel=texteingabe("Bitte geben Sie den neuen Songtitel ein.\n");
    song.songtitel=neuer_songtitel;
}
void kuenstlername_song_bearbeiten(Song song){
    std::string neuer_kuenstlername=texteingabe("Bitte geben Sie den neuen Künstlernamen ein.\n");
    song.kuenstlername=neuer_kuenstlername;
}
void erscheinungsjahr_song_bearbeiten(Song song){
    int neues_erscheinungsjahr=zahleingabe("Bitte geben Sie das neue Erscheinungsjahr ein.\n");
    song.erscheinungsjahr=neues_erscheinungsjahr;
}
void songlaenge_bearbeiten(Song song){
    int neue_songlaenge=zahleingabe("Bitte geben Sie die neue Songlaenge ein.\n");
    int differenz=neue_songlaenge-song.songlaenge;
    song.album.albumlaenge+=differenz;
    song.songlaenge=neue_songlaenge;
}
void genre_song_bearbeiten(Song song){
    std::string neues_genre=texteingabe("Bitte geben Sie das neue Genre ein.\n");
    song.genre=neues_genre;
}
void albumname_bearbeiten(Album album){
    std::string neuer_albumname=texteingabe("Bitte geben Sie den neuen Albumnamen ein.\n");
    album.albumname=neuer_albumname;
}
void kuenstlername_album_bearbeiten(Album album){
    std::string neuer_kuenstlername=texteingabe("Bitte geben Sie den neuen Künstlernamen ein.\n");
    album.kuenstlername=neuer_kuenstlername;
}
void erscheinungsjahr_album_bearbeiten(Album album){
    int neues_erscheinungsjahr=zahleingabe("Bitte geben Sie das neue Erscheinungsjahr ein.\n");
    album.erscheinungsjahr=neues_erscheinungsjahr;
}
void album_von_song_bearbeiten(Song song){
    std::string suchbegriff=texteingabe("Bitte geben Sie einen Suchbegriff ein, um das entsprechende Album zu suchen.\n");
    Album* suchergebnisse=(Album*) malloc((anzahl_alben)*sizeof(Album));
    int anzahl_ergebnisse=alben_suchen(suchergebnisse, suchbegriff);
    if (anzahl_ergebnisse==0){
        std::cout<<"Zu diesem Suchbegriff gibt es leider keine passenden Alben.";
        return;
    }
    std::cout<<"Zu diesem Suchbegriff gibt es "+std::to_string(anzahl_ergebnisse)+" Treffer.\n";
    std::cout<<"0: Zurück zum Hauptmenü";
    for (int i=0;i<anzahl_ergebnisse;i++){
        std::cout<<std::to_string(i+1)+": "+suchergebnisse[i].to_string_ausgabe();
    }
    int auswahl=-1;
    while (auswahl<0||auswahl>anzahl_ergebnisse){
        auswahl=zahleingabe("Bitte wählen Sie mit einer Zahleneingabe aus, welche Musik Sie bearbeiten möchten oder gehen sie mit 0 zurück zum Hauptmenü.\n");
        if (auswahl<0||auswahl>anzahl_ergebnisse){
            std::cout<<"Ungültige Auswahl!\n";
        }
    }
    if(auswahl==0){
        return;
    }
    song_von_album_entfernen(song.album, song);
    song.album=suchergebnisse[auswahl-1];
    song_zu_album_hinzufuegen(suchergebnisse[auswahl-1], song);
}
void song_von_album_bearbeiten(Album album){
    std::cout<<"0: Zurück zum Hauptmenü.\n";
    std::cout<<"1: Einen Song zu diesem Album hinzufügen.\n";
    std::cout<<"2: Einen Song aus diesem Album entfernen.\n";
    int auswahl_aktion=-1;
    while(auswahl_aktion<0||auswahl_aktion>2){
        auswahl_aktion=zahleingabe("Bitte wählen Sie mit einer Zahleneingabe aus, welche Musik Sie bearbeiten möchten oder gehen sie mit 0 zurück zum Hauptmenü.\n");
        if (auswahl_aktion<0||auswahl_aktion>2){
            std::cout<<"Ungültige Auswahl!\n";
        }
    }
    if(auswahl_aktion==1){
        std::string suchbegriff=texteingabe("Bitte geben Sie einen Suchbegriff ein, um den entsprechenden Song zu suchen.\n");
        Song* suchergebnisse=(Song*) malloc((anzahl_songs)*sizeof(Song));
        int anzahl_ergebnisse=songs_suchen(suchergebnisse, suchbegriff);
        if (anzahl_ergebnisse==0){
            std::cout<<"Zu diesem Suchbegriff gibt es leider keine passenden Songs.";
            return;
        }
        std::cout<<"Zu diesem Suchbegriff gibt es "+std::to_string(anzahl_ergebnisse)+" Treffer.\n";
        std::cout<<"0: Zurück zum Hauptmenü";
        for (int i=0;i<anzahl_ergebnisse;i++){
            std::cout<<std::to_string(i+1)+": "+suchergebnisse[i].to_string_ausgabe();
        }
        int auswahl_song=-1;
        while (auswahl_song<0||auswahl_song>anzahl_ergebnisse){
            auswahl_song=zahleingabe("Bitte wählen Sie mit einer Zahleneingabe aus, welchen Song Sie bearbeiten möchten oder gehen sie mit 0 zurück zum Hauptmenü.\n");
            if (auswahl_song<0||auswahl_song>anzahl_ergebnisse){
                std::cout<<"Ungültige Auswahl!\n";
            }
        }
        if(auswahl_song==0){
            return;
        }
        song_zu_album_hinzufuegen(album, suchergebnisse[auswahl_song-1]);
    }
    if(auswahl_aktion==2){
        if(album.songanzahl==0){
            std::cout<<"In diesem Album gibt es keine Songs, die man entfernen kann!\n";
        }
        else{
            std::cout<<"0: Zurück zum Hauptmenü";
            for (int i=0;i<album.songanzahl;i++){
                std::cout<<std::to_string(i+1)+": "+album.songliste[i].to_string_ausgabe();
            }
            int auswahl_song=-1;
            while (auswahl_song<0||auswahl_song>album.songanzahl){
                auswahl_song=zahleingabe("Bitte wählen Sie mit einer Zahleneingabe aus, welchen Song Sie bearbeiten möchten oder gehen sie mit 0 zurück zum Hauptmenü.\n");
                if (auswahl_song<0||auswahl_song>album.songanzahl){
                    std::cout<<"Ungültige Auswahl!\n";
                }
            }
            if(auswahl_song==0){
                return;
            }
            song_von_album_entfernen(album, album.songliste[auswahl_song-1]);
        }
    }
}
void suchen(){
    std::string suchbegriff=texteingabe("Bitte geben Sie einen Suchbegriff ein.\n");
    Song* suchergebnisse_songs=(Song*) malloc((anzahl_songs)*sizeof(Song));
    int anzahl_suchergebnisse_songs=songs_suchen(suchergebnisse_songs, suchbegriff);
    Album* suchergebnisse_alben=(Album*) malloc((anzahl_songs)*sizeof(Album));
    int anzahl_suchergebnisse_alben=alben_suchen(suchergebnisse_alben, suchbegriff);
    if (anzahl_suchergebnisse_songs+anzahl_suchergebnisse_alben==0){
        std::cout<<"Zu diesem Suchbegriff gibt es leider keine Treffer.";
        return;
    }
    std::cout<<"Zu diesem Suchbegriff gibt es "+std::to_string(anzahl_suchergebnisse_songs+anzahl_suchergebnisse_alben)+" Treffer.\n";
    std::cout<<"0: Zurück zum Hauptmenü";
    for (int i=0;i<anzahl_suchergebnisse_songs;i++){
        std::cout<<std::to_string(i+1)+": "+suchergebnisse_songs[i].to_string_ausgabe();
    }
    for (int i=0;i<anzahl_suchergebnisse_alben;i++){
        std::cout<<std::to_string(anzahl_suchergebnisse_songs+i+1)+": "+suchergebnisse_alben[i].to_string_ausgabe();
    }
    int auswahl_musik=-1;
    while (auswahl_musik<0||auswahl_musik>anzahl_suchergebnisse_songs+anzahl_suchergebnisse_alben){
        auswahl_musik=zahleingabe("Bitte wählen Sie mit einer Zahleneingabe aus, welche Musik Sie bearbeiten möchten oder gehen sie mit 0 zurück zum Hauptmenü.\n");
        if (auswahl_musik<0||auswahl_musik>anzahl_suchergebnisse_songs+anzahl_suchergebnisse_alben){
            std::cout<<"Ungültige Auswahl!\n";
        }
    }
    if (auswahl_musik==0){
        return;
    }
    int auswahl_aktion=-1;
    if (auswahl_musik<=anzahl_songs){
        Song song_auswahl=suchergebnisse_songs[auswahl_musik-1];
        std::cout<<"Der Song wurde ausgewählt. Folgende Aktionen stehen zur Verfügung:";
        std::cout<<"0: Zurück zum Hauptmenü";
        std::cout<<"1: Songtitel bearbeiten\n";
        std::cout<<"2: Album bearbeiten\n";
        std::cout<<"3: Künstlername bearbeiten\n";
        std::cout<<"4: Erscheinungsjahr bearbeiten\n";
        std::cout<<"5: Songlänge bearbeiten\n";
        std::cout<<"6: Genre bearbeiten\n";
        std::cout<<"7: Song löschen\n";
        while(auswahl_aktion<0||auswahl_aktion>7){
            auswahl_aktion=zahleingabe("Bitte wählen Sie mit einer Zahleneingabe aus, welche Aktion Sie ausführen möchten.\n");
            switch(auswahl_aktion){
                case 0: break;
                case 1: songtitel_bearbeiten(song_auswahl); break;
                case 2: album_von_song_bearbeiten(song_auswahl); break;
                case 3: kuenstlername_song_bearbeiten(song_auswahl); break;
                case 4: erscheinungsjahr_song_bearbeiten(song_auswahl); break;
                case 5: songlaenge_bearbeiten(song_auswahl); break;
                case 6: genre_song_bearbeiten(song_auswahl); break;
                case 7: song_loeschen(song_auswahl); break;
                default: std::cout<<"Ungültige Auswahl!\n"; break;
            }
        }
    }
    else{
        Album album_auswahl=suchergebnisse_alben[auswahl_musik-anzahl_suchergebnisse_songs-1];
        std::cout<<"Das Album wurde ausgewählt. Folgende Aktionen stehen zur Verfügung:";
        std::cout<<"0: Zurück zum Hauptmenü";
        std::cout<<"1: Albumname bearbeiten\n";
        std::cout<<"2: Künstlername bearbeiten\n";
        std::cout<<"3: Song zu Album hinzufügen/entfernen\n";
        std::cout<<"4: Erscheinungsjahr bearbeiten\n";
        std::cout<<"5: Album löschen\n";
        while(auswahl_aktion<0||auswahl_aktion>5){
            auswahl_aktion=zahleingabe("Bitte wählen Sie mit einer Zahleneingabe aus, welche Aktion Sie ausführen möchten.\n");
            switch(auswahl_aktion){
                case 0: break;
                case 1: albumname_bearbeiten(album_auswahl); break;
                case 2: kuenstlername_album_bearbeiten(album_auswahl); break;
                case 3: song_von_album_bearbeiten(album_auswahl); break;
                case 4: erscheinungsjahr_album_bearbeiten(album_auswahl); break;
                case 5: album_loeschen(album_auswahl); break;
                default: std::cout<<"Ungültige Auswahl!\n"; break;
            }
        }
    }
}
int main(){
    int auswahl=0;
    while(auswahl!=6){
        std::cout<<"1: Bestehende Bibliothek einlesen\n";
        std::cout<<"2: Aktuelle Bibliothek speichern\n";
        std::cout<<"3: Song hinzufügen\n";
        std::cout<<"4: Album hinzufügen\n";
        std::cout<<"5: Songs/Alben suchen und bearbeiten\n";
        std::cout<<"6: Programm beenden\n";
        while(auswahl<1||auswahl>6){
            auswahl=zahleingabe("Bitte wählen Sie mit einer Zahleneingabe aus, welche Aktion Sie ausführen möchten.\n");
            switch(auswahl){
                case 1: bibliothek_einlesen(); break;
                case 2: bibliothek_abspeichern(); break;
                case 3: song_eingeben(); break;
                case 4: album_eingeben(); break;
                case 5: suchen(); break;
                case 6: break;
                default: std::cout<<"Ungültige Auswahl!\n"; break;
            }
        }
    }
}