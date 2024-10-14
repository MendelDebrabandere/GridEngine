//
// Created by mendel on 10/14/24.
//

#ifndef GEPIPELINE_H
#define GEPIPELINE_H
#include <string>
#include <vector>

namespace GE {

class GEPipeline {
public:
	GEPipeline(const std::string& vertFilepath, const std::string& fragFilepath);

private:
	static std::vector<char> readFile(const std::string& filepath);

	void createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath);
};

} // GE

#endif //GEPIPELINE_H
