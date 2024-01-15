#define CATCH_CONFIG_MAIN
#include "Musikbibliothek.h"
#include "catch/catch.hpp"
TEST_CASE("Test Song hinzufügen"){
    SECTION("Meta-Daten Test"){
        song_hinzufuegen("KMDF", "Haftbefehl feat. Shindy", 2020, 227, "Rap");
        REQUIRE(songs[0].songtitel=="KMDF");
        REQUIRE(songs[0].kuenstlername=="Haftbefehl feat. Shindy");
        REQUIRE(songs[0].erscheinungsjahr==2020);
        REQUIRE(songs[0].songlaenge==227);
        REQUIRE(songs[0].genre=="Rap");
    }
    SECTION("Anzahl Songs Test"){
        song_hinzufuegen("Bolon", "Haftbefehl feat. Bazzazian", 2020, 194, "Rap");
        song_hinzufuegen("Morgenstern", "Haftbefehl", 2020, 188, "Rap");
        song_hinzufuegen("KMDF", "Haftbefehl feat. Shindy", 2020, 227, "Rap");
        song_hinzufuegen("Für immer reich", "Haftbefehl", 2020, 192, "Rap");
        song_hinzufuegen("1999 Pt. 4 (AloAlo)", "Haftbefehl feat. Bazzazian", 2020, 116, "Rap");
        song_hinzufuegen("RADW", "Haftbefehl feat. Bazzazian", 2020, 196, "Rap");
        song_hinzufuegen("Ice", "Haftbefehl feat. Gucci Mane", 2020, 193, "Rap");
        song_hinzufuegen("Conan x Xenia", "Haftbefehl feat. Bazzazian, Shirin David", 2020, 200, "Rap");
        song_hinzufuegen("1999 Pt. 5 (Mainpark Baby)", "Haftbefehl feat. Bazzazian", 2020, 191, "Rap");
        song_hinzufuegen("Hotelzimmer", "Haftbefehl feat. Bazzazian", 2020, 169, "Rap");
        song_hinzufuegen("Trapking", "Haftbefehl feat. Ufo361", 2020, 190, "Rap");
        song_hinzufuegen("Depression & Schmerz", "Haftbefehl feat. Bazzazian, Capo", 2020, 189, "Rap");
        song_hinzufuegen("Papa war ein Rolling Stone", "Haftbefehl feat. Marteria", 2020, 219, "Rap");
        song_hinzufuegen("1999 Pt. 6 (Gabriel vs. Luzifer)", "Haftbefehl feat. Bazzazian", 2020, 145, "Rap");
        REQUIRE(anzahl_songs==14);
    }
}
TEST_CASE("Test Album hinzufügen"){
    SECTION("Meta-Daten Test"){
        song_hinzufuegen("Bolon", "Haftbefehl feat. Bazzazian", 2020, 194, "Rap");
        song_hinzufuegen("Morgenstern", "Haftbefehl", 2020, 188, "Rap");
        song_hinzufuegen("KMDF", "Haftbefehl feat. Shindy", 2020, 227, "Rap");
        song_hinzufuegen("Für immer reich", "Haftbefehl", 2020, 192, "Rap");
        song_hinzufuegen("1999 Pt. 4 (AloAlo)", "Haftbefehl feat. Bazzazian", 2020, 116, "Rap");
        song_hinzufuegen("RADW", "Haftbefehl feat. Bazzazian", 2020, 196, "Rap");
        song_hinzufuegen("Ice", "Haftbefehl feat. Gucci Mane", 2020, 193, "Rap");
        song_hinzufuegen("Conan x Xenia", "Haftbefehl feat. Bazzazian, Shirin David", 2020, 200, "Rap");
        song_hinzufuegen("1999 Pt. 5 (Mainpark Baby)", "Haftbefehl feat. Bazzazian", 2020, 191, "Rap");
        song_hinzufuegen("Hotelzimmer", "Haftbefehl feat. Bazzazian", 2020, 169, "Rap");
        song_hinzufuegen("Trapking", "Haftbefehl feat. Ufo361", 2020, 190, "Rap");
        song_hinzufuegen("Depression & Schmerz", "Haftbefehl feat. Bazzazian, Capo", 2020, 189, "Rap");
        song_hinzufuegen("Papa war ein Rolling Stone", "Haftbefehl feat. Marteria", 2020, 219, "Rap");
        song_hinzufuegen("1999 Pt. 6 (Gabriel vs. Luzifer)", "Haftbefehl feat. Bazzazian", 2020, 145, "Rap");
        Song* test_songs=(Song*)malloc(14*sizeof(Song));
        for (int i=0; i<14; i++){
            test_songs[i]=songs[i];
        }
        album_hinzufuegen("Das weisse Album", "Haftbefehl", songs, 2020, 14, 2619);
        REQUIRE(anzahl_alben==1);
        REQUIRE(alben[0].albumname=="Das weisse Album");
        REQUIRE(alben[0].kuenstlername=="Haftbefehl");
        REQUIRE(alben[0].erscheinungsjahr==2020);
        REQUIRE(alben[0].songanzahl==14);
        REQUIRE(alben[0].albumlaenge==2619);

    }
}
TEST_CASE("Suchen"){
    SECTION("Ergebnisse der Meta-Daten"){
        song_hinzufuegen("Bolon", "Haftbefehl feat. Bazzazian", 2020, 194, "Rap");
        song_hinzufuegen("Morgenstern", "Haftbefehl", 2020, 188, "Rap");
        song_hinzufuegen("KMDF", "Haftbefehl feat. Shindy", 2020, 227, "Rap");
        song_hinzufuegen("Für immer reich", "Haftbefehl", 2020, 192, "Rap");
        song_hinzufuegen("1999 Pt. 4 (AloAlo)", "Haftbefehl feat. Bazzazian", 2020, 116, "Rap");
        song_hinzufuegen("RADW", "Haftbefehl feat. Bazzazian", 2020, 196, "Rap");
        song_hinzufuegen("Ice", "Haftbefehl feat. Gucci Mane", 2020, 193, "Rap");
        song_hinzufuegen("Conan x Xenia", "Haftbefehl feat. Bazzazian, Shirin David", 2020, 200, "Rap");
        song_hinzufuegen("1999 Pt. 5 (Mainpark Baby)", "Haftbefehl feat. Bazzazian", 2020, 191, "Rap");
        song_hinzufuegen("Hotelzimmer", "Haftbefehl feat. Bazzazian", 2020, 169, "Rap");
        song_hinzufuegen("Trapking", "Haftbefehl feat. Ufo361", 2020, 190, "Rap");
        song_hinzufuegen("Depression & Schmerz", "Haftbefehl feat. Bazzazian, Capo", 2020, 189, "Rap");
        song_hinzufuegen("Papa war ein Rolling Stone", "Haftbefehl feat. Marteria", 2020, 219, "Rap");
        song_hinzufuegen("1999 Pt. 6 (Gabriel vs. Luzifer)", "Haftbefehl feat. Bazzazian", 2020, 145, "Rap");
        Song* suchergebnisse=(Song*)malloc(14*sizeof(Song));
        int anzahl_suchergebnisse=songs_suchen(suchergebnisse,"Bazzazian");
        REQUIRE(anzahl_suchergebnisse==8);
        REQUIRE(suchergebnisse[0].songtitel=="Bolbon");
        REQUIRE(suchergebnisse[0].songtitel=="1999 Pt. 4 (AloAlo)");
    }
}
TEST_CASE("Songs löschen"){
    SECTION("Anzahl Test"){
        song_hinzufuegen("Bolon", "Haftbefehl feat. Bazzazian", 2020, 194, "Rap");
        song_hinzufuegen("Morgenstern", "Haftbefehl", 2020, 188, "Rap");
        song_hinzufuegen("KMDF", "Haftbefehl feat. Shindy", 2020, 227, "Rap");
        song_loeschen(songs[0]);
        REQUIRE(anzahl_songs==2);
        REQUIRE(songs[0].songtitel=="Morgenstern");
    }
}
TEST_CASE("Songs zu Album hinzufügen"){
    SECTION("Meta-Daten Test"){
        song_hinzufuegen("Bolon", "Haftbefehl feat. Bazzazian", 2020, 194, "Rap");
        song_hinzufuegen("Morgenstern", "Haftbefehl", 2020, 188, "Rap");
        song_hinzufuegen("KMDF", "Haftbefehl feat. Shindy", 2020, 227, "Rap");
        Song* test_songs=(Song*)malloc(3*sizeof(Song));
        for (int i=0; i<3; i++){
            test_songs[i]=songs[i];
        }
        album_hinzufuegen("Das weisse Album (nicht vollständig)", "Haftbefehl", songs, 2020, 3, 609); // Album ist in alben[0]
        song_hinzufuegen("Für immer reich", "Haftbefehl", 2020, 192, "Rap"); //Neuer Song ist in songs[3], weil von 0 gezählt wird
        song_zu_album_hinzufuegen(alben[0], songs[3]);
        REQUIRE(alben[0].songanzahl==4);
        REQUIRE(alben[0].albumlaenge==609+192);
    }
}