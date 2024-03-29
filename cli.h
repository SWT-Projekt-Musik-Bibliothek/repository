#include "Musikbibliothek.h"
class Cli{
    public:
        Musikbibliothek musikbibliothek;
        std::string texteingabe(std::string aufforderung);
        std::string texteingabe_ohne_satzzeichen(std::string aufforderung);
        int zahleingabe(std::string aufforderung);
        void bibliothek_einlesen();
        void bibliothek_abspeichern();
        void song_eingeben();
        void album_eingeben();
        void songtitel_bearbeiten(Song song);
        void kuenstlername_song_bearbeiten(Song song);
        void erscheinungsjahr_song_bearbeiten(Song song);
        void songlaenge_bearbeiten(Song song);
        void genre_song_bearbeiten(Song song);
        void albumname_bearbeiten(Album album);
        void kuenstlername_album_bearbeiten(Album album);
        void erscheinungsjahr_album_bearbeiten(Album album);
        void album_von_song_bearbeiten(Song song);
        void song_von_album_bearbeiten(Album album);
        void suchen();
        int main();
};