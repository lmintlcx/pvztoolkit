
#pragma once

#include "zlib.h"

#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <cassert>
#include <fstream>

#include <Windows.h>

namespace Pt
{

#define GRID (6 * 9)

class Lineup
{
  public:
    Lineup();
    Lineup(std::string);
    Lineup(std::string, std::string);
    ~Lineup();

    bool may_sleep[48] = {false, false, false, false, false, false, false, false, //
                          true, true, true, false, true, true, true, true,        //
                          false, false, false, false, false, false, false, false, //
                          true, false, false, false, false, false, false, true,   //
                          false, false, false, false, false, false, false, false, //
                          false, false, true, false, false, false, false, false}; //

    void Init(const std::string &); // Formation string/code -> Data
    bool OK();                      //
    std::string Generate();         // Fill in the data-> formation code

    std::string lineup_name;   // Formation name
    std::string lineup_string; // Formation string
    std::string lineup_code;   // Formation code

    uint16_t plant[GRID];
    uint16_t plant_im[GRID];
    uint16_t plant_awake[GRID];
    uint16_t base[GRID];
    uint16_t base_im[GRID];
    uint16_t pumpkin[GRID];
    uint16_t pumpkin_im[GRID];
    uint16_t coffee[GRID];
    uint16_t coffee_im[GRID];
    uint16_t ladder[GRID];

    uint8_t rake_row;
    uint8_t scene;

    long long weight; // Weights used for sorting

  private:
    void reset_data();

    bool ok;
    uint16_t items[GRID]; // Compressed

    std::vector<std::string> split(const std::string &, char);
    long hex2dec(const std::string &);

    bool lineup_string_to_data();  // Formation string -> Data
    bool lineup_code_to_data();    // Formation code-> Data
    void data_to_lineup_code();    // Data-> Formation code
    inline void compress_data();   // Compressed array
    inline void decompress_data(); // Unzip the array
};

} // namespace Pt
