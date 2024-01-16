#include "song.h"
class Musikbibliothek{
    public:
        Album* alben;
        int anzahl_alben;
        Song* songs;
        int anzahl_songs;
        Album album_hinzufuegen(std::string albumname,std::string kuenstlername,Song* songliste,int erscheinungsjahr,int songanzahl,int albumlaenge);
        Song song_hinzufuegen(std::string songtitel, std::string kuenstlername,int erscheinungsjahr,int songlaenge,std::string genre);
        void song_zu_album_hinzufuegen(Album album, Song song);
        void song_von_album_entfernen(Album album, Song song);
        void album_loeschen(Album album);
        void song_loeschen(Song song);
        int songs_suchen(Song* suchergebnisse,std::string suchbegriff);
        int alben_suchen(Album* suchergebnisse,std::string suchbegriff);
        bool bibliothek_speichern(std::string speicherort);
        void bibliothek_leeren();
        bool bibliothek_laden(std::string speicherort);
};