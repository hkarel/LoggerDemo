import qbs
import "qbs/imports/QbsUtl/qbsutl.js" as QbsUtl

Project {
    name: "LoggerDemo (Project)"

    minimumQbsVersion: "1.15.0"
    qbsSearchPaths: ["qbs"]

    property var cppDefines: {
        var def = [];

        if (qbs.buildVariant === "release")
            def.push("NDEBUG");

        return def;
    }

    property var cxxFlags: [
        "-ggdb3",
        "-Wall",
        "-Wextra",
        "-Wdangling-else",
        "-Wno-unused-parameter",
        "-Wno-variadic-macros",
    ]
    property string cxxLanguageVersion: "c++14"

    references: [
        "src/shared/shared.qbs",
        "src/yaml/yaml.qbs",
    ]

    Product {
        name: "Demo 01"
        targetName: "demo01"
        condition: true

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

        files: [
            "src/shared/shared/logger/logger.cpp",
            "src/shared/shared/logger/logger.h",
            "src/shared/shared/thread/thread_base.cpp",
            "src/shared/shared/thread/thread_base.h",
            "src/shared/shared/thread/thread_utils.cpp",
            "src/shared/shared/thread/thread_utils.h",
            "src/shared/shared/utils.cpp",
            "src/shared/shared/utils.h",
            "src/demo01/demo01.cpp",
        ]
    }

}
