#define CATCH_CONFIG_MAIN
#include "Musikbibliothek.h"
#include "catch/catch.hpp"
TEST_CASE("Test Song hinzufügen"){
    Musikbibliothek musikbibliothek;
    SECTION("Meta-Daten Test"){
        musikbibliothek.song_hinzufuegen("KMDF", "Haftbefehl feat. Shindy", 2020, 227, "Rap");
        REQUIRE(musikbibliothek.songs[0].songtitel=="KMDF");
        REQUIRE(musikbibliothek.songs[0].kuenstlername=="Haftbefehl feat. Shindy");
        REQUIRE(musikbibliothek.songs[0].erscheinungsjahr==2020);
        REQUIRE(musikbibliothek.songs[0].songlaenge==227);
        REQUIRE(musikbibliothek.songs[0].genre=="Rap");
    }
    SECTION("Anzahl Songs Test"){
        musikbibliothek.song_hinzufuegen("Bolon", "Haftbefehl feat. Bazzazian", 2020, 194, "Rap");
        musikbibliothek.song_hinzufuegen("Morgenstern", "Haftbefehl", 2020, 188, "Rap");
        musikbibliothek.song_hinzufuegen("KMDF", "Haftbefehl feat. Shindy", 2020, 227, "Rap");
        musikbibliothek.song_hinzufuegen("Für immer reich", "Haftbefehl", 2020, 192, "Rap");
        musikbibliothek.song_hinzufuegen("1999 Pt. 4 (AloAlo)", "Haftbefehl feat. Bazzazian", 2020, 116, "Rap");
        musikbibliothek.song_hinzufuegen("RADW", "Haftbefehl feat. Bazzazian", 2020, 196, "Rap");
        musikbibliothek.song_hinzufuegen("Ice", "Haftbefehl feat. Gucci Mane", 2020, 193, "Rap");
        musikbibliothek.song_hinzufuegen("Conan x Xenia", "Haftbefehl feat. Bazzazian, Shirin David", 2020, 200, "Rap");
        musikbibliothek.song_hinzufuegen("1999 Pt. 5 (Mainpark Baby)", "Haftbefehl feat. Bazzazian", 2020, 191, "Rap");
        musikbibliothek.song_hinzufuegen("Hotelzimmer", "Haftbefehl feat. Bazzazian", 2020, 169, "Rap");
        musikbibliothek.song_hinzufuegen("Trapking", "Haftbefehl feat. Ufo361", 2020, 190, "Rap");
        musikbibliothek.song_hinzufuegen("Depression & Schmerz", "Haftbefehl feat. Bazzazian, Capo", 2020, 189, "Rap");
        musikbibliothek.song_hinzufuegen("Papa war ein Rolling Stone", "Haftbefehl feat. Marteria", 2020, 219, "Rap");
        musikbibliothek.song_hinzufuegen("1999 Pt. 6 (Gabriel vs. Luzifer)", "Haftbefehl feat. Bazzazian", 2020, 145, "Rap");
        REQUIRE(musikbibliothek.anzahl_songs==14);
    }
}
TEST_CASE("Test Album hinzufügen"){
    Musikbibliothek musikbibliothek;
    SECTION("Meta-Daten Test"){
        musikbibliothek.song_hinzufuegen("Bolon", "Haftbefehl feat. Bazzazian", 2020, 194, "Rap");
        musikbibliothek.song_hinzufuegen("Morgenstern", "Haftbefehl", 2020, 188, "Rap");
        musikbibliothek.song_hinzufuegen("KMDF", "Haftbefehl feat. Shindy", 2020, 227, "Rap");
        musikbibliothek.song_hinzufuegen("Für immer reich", "Haftbefehl", 2020, 192, "Rap");
        musikbibliothek.song_hinzufuegen("1999 Pt. 4 (AloAlo)", "Haftbefehl feat. Bazzazian", 2020, 116, "Rap");
        musikbibliothek.song_hinzufuegen("RADW", "Haftbefehl feat. Bazzazian", 2020, 196, "Rap");
        musikbibliothek.song_hinzufuegen("Ice", "Haftbefehl feat. Gucci Mane", 2020, 193, "Rap");
        musikbibliothek.song_hinzufuegen("Conan x Xenia", "Haftbefehl feat. Bazzazian, Shirin David", 2020, 200, "Rap");
        musikbibliothek.song_hinzufuegen("1999 Pt. 5 (Mainpark Baby)", "Haftbefehl feat. Bazzazian", 2020, 191, "Rap");
        musikbibliothek.song_hinzufuegen("Hotelzimmer", "Haftbefehl feat. Bazzazian", 2020, 169, "Rap");
        musikbibliothek.song_hinzufuegen("Trapking", "Haftbefehl feat. Ufo361", 2020, 190, "Rap");
        musikbibliothek.song_hinzufuegen("Depression & Schmerz", "Haftbefehl feat. Bazzazian, Capo", 2020, 189, "Rap");
        musikbibliothek.song_hinzufuegen("Papa war ein Rolling Stone", "Haftbefehl feat. Marteria", 2020, 219, "Rap");
        musikbibliothek.song_hinzufuegen("1999 Pt. 6 (Gabriel vs. Luzifer)", "Haftbefehl feat. Bazzazian", 2020, 145, "Rap");
        Song* test_songs=(Song*)malloc(14*sizeof(Song));
        for (int i=0; i<14; i++){
            test_songs[i]=musikbibliothek.songs[i];
        }
        musikbibliothek.album_hinzufuegen("Das weisse Album", "Haftbefehl", test_songs, 2020, 14, 2619);
        REQUIRE(musikbibliothek.anzahl_alben==1);
        REQUIRE(musikbibliothek.alben[0].albumname=="Das weisse Album");
        REQUIRE(musikbibliothek.alben[0].kuenstlername=="Haftbefehl");
        REQUIRE(musikbibliothek.alben[0].erscheinungsjahr==2020);
        REQUIRE(musikbibliothek.alben[0].songanzahl==14);
        REQUIRE(musikbibliothek.alben[0].albumlaenge==2619);

    }
}
TEST_CASE("Suchen"){
    Musikbibliothek musikbibliothek;
    SECTION("Ergebnisse der Meta-Daten"){
        musikbibliothek.song_hinzufuegen("Bolon", "Haftbefehl feat. Bazzazian", 2020, 194, "Rap");
        musikbibliothek.song_hinzufuegen("Morgenstern", "Haftbefehl", 2020, 188, "Rap");
        musikbibliothek.song_hinzufuegen("KMDF", "Haftbefehl feat. Shindy", 2020, 227, "Rap");
        musikbibliothek.song_hinzufuegen("Für immer reich", "Haftbefehl", 2020, 192, "Rap");
        musikbibliothek.song_hinzufuegen("1999 Pt. 4 (AloAlo)", "Haftbefehl feat. Bazzazian", 2020, 116, "Rap");
        musikbibliothek.song_hinzufuegen("RADW", "Haftbefehl feat. Bazzazian", 2020, 196, "Rap");
        musikbibliothek.song_hinzufuegen("Ice", "Haftbefehl feat. Gucci Mane", 2020, 193, "Rap");
        musikbibliothek.song_hinzufuegen("Conan x Xenia", "Haftbefehl feat. Bazzazian, Shirin David", 2020, 200, "Rap");
        musikbibliothek.song_hinzufuegen("1999 Pt. 5 (Mainpark Baby)", "Haftbefehl feat. Bazzazian", 2020, 191, "Rap");
        musikbibliothek.song_hinzufuegen("Hotelzimmer", "Haftbefehl feat. Bazzazian", 2020, 169, "Rap");
        musikbibliothek.song_hinzufuegen("Trapking", "Haftbefehl feat. Ufo361", 2020, 190, "Rap");
        musikbibliothek.song_hinzufuegen("Depression & Schmerz", "Haftbefehl feat. Bazzazian, Capo", 2020, 189, "Rap");
        musikbibliothek.song_hinzufuegen("Papa war ein Rolling Stone", "Haftbefehl feat. Marteria", 2020, 219, "Rap");
        musikbibliothek.song_hinzufuegen("1999 Pt. 6 (Gabriel vs. Luzifer)", "Haftbefehl feat. Bazzazian", 2020, 145, "Rap");
        Song* suchergebnisse=(Song*)malloc(14*sizeof(Song));
        int anzahl_suchergebnisse=musikbibliothek.songs_suchen(suchergebnisse,"Bazzazian");
        REQUIRE(anzahl_suchergebnisse==8);
        REQUIRE(suchergebnisse[0].songtitel=="Bolbon");
        REQUIRE(suchergebnisse[1].songtitel=="1999 Pt. 4 (AloAlo)");
        REQUIRE(suchergebnisse[2].songtitel=="RADW");
        REQUIRE(suchergebnisse[3].songtitel=="Conan x Xenia");
        REQUIRE(suchergebnisse[4].songtitel=="1999 Pt. 5 (Mainpark Baby)");
        REQUIRE(suchergebnisse[5].songtitel=="Hotelzimmer");
        REQUIRE(suchergebnisse[6].songtitel=="Depression & Schmerz");
        REQUIRE(suchergebnisse[7].songtitel=="1999 Pt. 6 (Gabriel vs. Luzifer)");
    }
}
TEST_CASE("Songs löschen"){
    Musikbibliothek musikbibliothek;
    SECTION("Anzahl Test"){
        musikbibliothek.song_hinzufuegen("Bolon", "Haftbefehl feat. Bazzazian", 2020, 194, "Rap");
        musikbibliothek.song_hinzufuegen("Morgenstern", "Haftbefehl", 2020, 188, "Rap");
        musikbibliothek.song_hinzufuegen("KMDF", "Haftbefehl feat. Shindy", 2020, 227, "Rap");
        musikbibliothek.song_loeschen(musikbibliothek.songs[0]);
        REQUIRE(musikbibliothek.anzahl_songs==2);
        REQUIRE(musikbibliothek.songs[0].songtitel=="Morgenstern");
        REQUIRE(musikbibliothek.songs[1].songtitel=="KMDF");
    }
}
TEST_CASE("Songs zu Album hinzufügen"){
    Musikbibliothek musikbibliothek;
    SECTION("Meta-Daten Test"){
        musikbibliothek.song_hinzufuegen("Bolon", "Haftbefehl feat. Bazzazian", 2020, 194, "Rap");
        musikbibliothek.song_hinzufuegen("Morgenstern", "Haftbefehl", 2020, 188, "Rap");
        musikbibliothek.song_hinzufuegen("KMDF", "Haftbefehl feat. Shindy", 2020, 227, "Rap");
        Song* test_songs=(Song*)malloc(3*sizeof(Song));
        for (int i=0; i<3; i++){
            test_songs[i]=musikbibliothek.songs[i];
        }
        musikbibliothek.album_hinzufuegen("Das weisse Album (nicht vollständig)", "Haftbefehl", test_songs, 2020, 3, 609); 
        musikbibliothek.song_hinzufuegen("Für immer reich", "Haftbefehl", 2020, 192, "Rap");
        musikbibliothek.song_zu_album_hinzufuegen(musikbibliothek.alben[0], musikbibliothek.songs[3]);
        REQUIRE(musikbibliothek.alben[0].songanzahl==4);
        REQUIRE(musikbibliothek.alben[0].albumlaenge==609+192);
    }
}