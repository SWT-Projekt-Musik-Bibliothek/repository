#include "album.h"
std::string Album::to_string_csv(){
    return albumname+";"+kuenstlername+";"+std::to_string(erscheinungsjahr)+";"+std::to_string(songanzahl)+";"+std::to_string(albumlaenge)+"\n";
}
std::string Album::to_string_ausgabe(){
    return albumname+" - "+kuenstlername+" ("+std::to_string(erscheinungsjahr)+"): "+std::to_string(songanzahl)+" Songs, "+std::to_string(albumlaenge)+" Sekunden Länge\n";
}