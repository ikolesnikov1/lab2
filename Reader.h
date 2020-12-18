#pragma once

class Reader {
public:
    static void splitString(std::list <std::string>&, const std::string&);
    static bool readNextString(std::istream& is, std::list <std::string>& args);
};