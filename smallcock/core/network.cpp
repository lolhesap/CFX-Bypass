#include "network.hpp"

void network::block_connection(std::string process)
{
	std::string outbound = "netsh advfirewall firewall add rule name = " + process + " dir = out program = " + process + "  action = block";
	system(outbound.c_str());

	std::string inbound = "netsh advfirewall firewall add rule name = " + process + " dir = in program = " + process + "  action = block";
	system(inbound.c_str());
}

void network::unblock_connection(std::string process)
{
	std::string outbound = "netsh advfirewall firewall delete rule name = " + process + " dir = out program = " + process;
	system(outbound.c_str());

	std::string inbound = "netsh advfirewall firewall delete rule name = " + process + " dir = in program = " + process;
	system(inbound.c_str());
}

void network::setup()
{
	std::string appdata = getenv("LOCALAPPDATA");

	// Locate FiveM.exe
	auto fivem_path = appdata + "\\" + "FiveM" + "\\" + "FiveM.exe";
	block_connection(fivem_path);


	// Locate FiveM Subprocesses path
	auto subprocess_path = appdata + "\\" + "FiveM" + "\\" + "FiveM.app" + "\\" + "data" + "\\" + "cache" + "\\" "subprocess";

	std::vector<std::string> gta_versions{ "b2545", "b2372", "b2189", "b2060",  "" };

	for (auto processes : gta_versions)
	{
		// Block the gta processes
		auto gta_process = subprocess_path + "\\" + "FiveM_" + processes + "_GTAProcess.exe";
		block_connection(gta_process);

		// Block the steam processes
		auto steam_process = subprocess_path + "\\" + "FiveM_" + processes + "_SteamChild.exe";
		block_connection(steam_process);
	}

}

void network::destroy()
{
	std::string appdata = getenv("LOCALAPPDATA");

	// Locate FiveM.exe
	auto fivem_path = appdata + "\\" + "FiveM" + "\\" + "FiveM.exe";
	unblock_connection(fivem_path);

	// Locate FiveM Subprocesses path
	auto subprocess_path = appdata + "\\" + "FiveM" + "\\" + "FiveM.app" + "\\" + "data" + "\\" + "cache" + "\\" "subprocess";

	std::vector<std::string> gta_versions{ "b2545", "b2372", "b2189", "b2060",  "" };

	for (auto processes : gta_versions)
	{
		// Block the gta processes
		auto gta_process = subprocess_path + "\\" + "FiveM_" + processes + "_GTAProcess.exe";
		unblock_connection(gta_process);

		// Block the steam processes
		auto steam_process = subprocess_path + "\\" + "FiveM_" + processes + "_SteamChild.exe";
		unblock_connection(steam_process);
	}
}