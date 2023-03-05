#include "json11/json11.hpp"
#include <iostream>
#include <fstream>

using namespace json11;
int main() {
    std::ofstream ofile("c.json", std::ios_base::out);
    Json::array slice_info;
    
    Json tmp_slice = Json::object({
            {"stage_index" , Json::array({1, 2, 3})},
            {"stream_index" , Json::array({10, 20, 30})},
            {"single_time" , 500},
    });
    std::string key = "slice_"+std::to_string(0);
    for (int i = 0; i < 2; i++) {
        key = "slice_"+std::to_string(i);
        slice_info.push_back(Json::object({
            {key, tmp_slice},
        }));
    }

    Json json = Json::object({
        {"slice_info", slice_info}
    }); 
    std::string json_str = json.dump();
    ofile << json_str << std::endl;

    // Json a = Json::array {1, 2};
    // ofile << a.dump();
    ofile.close();
    return 0;
}