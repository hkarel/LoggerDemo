import qbs

Product {
    type: "application"
    consoleApplication: true
    destinationDirectory: "./"

    Depends { name: "cpp" }
    Depends { name: "cppstdlib" }

    cpp.defines: project.cppDefines
    cpp.cxxFlags: project.cxxFlags
    cpp.cxxLanguageVersion: project.cxxLanguageVersion

    cpp.includePaths: [
        "src/shared",
        "src/shared/shared",
    ]

    cpp.dynamicLibraries: [
        "pthread",
    ]

    property var baseFiles: [
        "src/shared/shared/logger/logger.cpp",
        "src/shared/shared/logger/logger.h",
        "src/shared/shared/thread/thread_base.cpp",
        "src/shared/shared/thread/thread_base.h",
        "src/shared/shared/thread/thread_utils.cpp",
        "src/shared/shared/thread/thread_utils.h",
        "src/shared/shared/utils.cpp",
        "src/shared/shared/utils.h",
    ]
}
