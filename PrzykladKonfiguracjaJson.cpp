#include "json.hpp"
#include <vector>

nlohmann::json getExampleConfig() {

	nlohmann::json konfiguruj =
	{
		"Obiekt1",
			{
				"A",
					nlohmann::json::array({ 1, -.5, .7 }),
				"B",
					nlohmann::json::array({ .3, .8 }),
				"k",
					{
						1
					}
			},
		"Obiekt2",
			{
				"A",
					nlohmann::json::array({ 1, -.9 }),
				"B",
					{
						.1
					},
				"k",
					{
						2
					}
			},
		"pid1",
			{
				"k",
					{
						1.1
					},
				"Ti",
					{
						.5
					},
				"Td",
					{
						0
					}
			},
		"System",
			{
				"SimTime",
					{
						200
					}
			}
	};
	return konfiguruj;
}