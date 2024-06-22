
#pragma once

#include <algorithm>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

#include <FL/images/zlib.h>

#include "utils.h"

namespace Pt
{

#define GRID (6 * 9)

class Lineup
{
  public:
    Lineup();
    Lineup(const std::string &);
    Lineup(const std::string &, const std::string &);
    ~Lineup();

    bool may_sleep[48] = {false, false, false, false, false, false, false, false, //
                          true, true, true, false, true, true, true, true,        //
                          false, false, false, false, false, false, false, false, //
                          true, false, false, false, false, false, false, true,   //
                          false, false, false, false, false, false, false, false, //
                          false, false, true, false, false, false, false, false}; //

    void Init(const std::string &); // 阵型字符串/代码 -> 数据
    bool OK();                      //
    std::string Generate();         // 填充数据 -> 阵型代码

    std::string lineup_name;   // 阵型名称
    std::string lineup_string; // 阵型字符串
    std::string lineup_code;   // 阵型代码

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

    long long weight; // 用于排序的权重

  private:
    void reset_data();

    bool ok;
    uint16_t items[GRID]; // 压缩的

    std::vector<std::string> split(const std::string &, char);
    long hex2dec(const std::string &);

    bool lineup_string_to_data();  // 阵型字符串 -> 数据
    bool lineup_code_to_data();    // 阵型代码 -> 数据
    void data_to_lineup_code();    // 数据 -> 阵型代码
    inline void compress_data();   // 压缩数组
    inline void decompress_data(); // 解压数组
};

} // namespace Pt
