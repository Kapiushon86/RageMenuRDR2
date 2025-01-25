#ifndef CONFIG_H
#define CONFIG_H

#include <string>

class Config {
public:
    std::string GetRDR2Path();
    std::string GetRootFolderPath();
    std::string GetLogsFolderPath();
    std::string GetConfigsFolderPath();
    std::string GetUtilsFolderPath();
    std::string GetSkipIntroFolderPath();
    std::string GetWavPlayerFolderPath();
    std::string GetLogFilePath();
    std::string GetDateSpecificFolderPath();

    bool CreateDirectoryStructure();
    bool VerifyFolderStructure();
    bool CleanupUnwantedFolders();
    bool CreateOptionsIniFile();
    bool CreateSettingsIniFile();
private:
    const std::string ROOT_FOLDER = "RageMenu";
    const std::string LOGS_FOLDER = "Logs";
    const std::string CONFIGS_FOLDER = "Configurations";
    const std::string UTILS_FOLDER = "Utils";
    const std::string SKIPINTRO_FOLDER = "SkipIntro";
    const std::string WAV_PLAYER_FOLDER = "WavPlayer";
    const std::string LOG_FILE_NAME = "RageMenu.log";
    const std::string INI_OPTIONS_FILE = "RageMenuOptions.ini";
    const std::string INI_SETTINGS_FILE = "RageMenuSettings.ini";
};

bool CreateFolderWithPermissions(const std::string& path);

#endif
