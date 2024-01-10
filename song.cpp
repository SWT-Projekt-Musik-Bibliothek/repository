#include "song.h"
std::string Song::to_string_csv(){
        return songtitel+";"+kuenstlername+";"+std::to_string(erscheinungsjahr)+";"+std::to_string(songlaenge)+";"+genre;
}
std::string Song::to_string_csv(){
        return songtitel+" ("+album.albumname+") - "+kuenstlername+" ("+std::to_string(erscheinungsjahr)+", "+genre+"): "+std::to_string(songlaenge)+" Sekunden Länge;\n";
}