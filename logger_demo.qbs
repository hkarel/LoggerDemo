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

    Product {
        name: "Demo 02"
        targetName: "demo02"
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
            "src/shared/shared/logger/format.h",
            "src/shared/shared/logger/logger.cpp",
            "src/shared/shared/logger/logger.h",
            "src/shared/shared/thread/thread_base.cpp",
            "src/shared/shared/thread/thread_base.h",
            "src/shared/shared/thread/thread_utils.cpp",
            "src/shared/shared/thread/thread_utils.h",
            "src/shared/shared/utils.cpp",
            "src/shared/shared/utils.h",
            "src/demo02/demo02.cpp",
        ]
    }

    Product {
        name: "Demo 03"
        targetName: "demo03"
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
            "src/shared/shared/logger/format.h",
            "src/shared/shared/logger/logger.cpp",
            "src/shared/shared/logger/logger.h",
            "src/shared/shared/thread/thread_base.cpp",
            "src/shared/shared/thread/thread_base.h",
            "src/shared/shared/thread/thread_utils.cpp",
            "src/shared/shared/thread/thread_utils.h",
            "src/shared/shared/utils.cpp",
            "src/shared/shared/utils.h",
            "src/demo03/demo03.cpp",
        ]
    }

    Product {
        name: "Demo 04"
        targetName: "demo04"
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
            "src/shared/shared/logger/format.h",
            "src/shared/shared/logger/logger.cpp",
            "src/shared/shared/logger/logger.h",
            "src/shared/shared/thread/thread_base.cpp",
            "src/shared/shared/thread/thread_base.h",
            "src/shared/shared/thread/thread_utils.cpp",
            "src/shared/shared/thread/thread_utils.h",
            "src/shared/shared/utils.cpp",
            "src/shared/shared/utils.h",
            "src/demo04/demo04.cpp",
            "src/demo04/module1.cpp",
            "src/demo04/module2.cpp",
        ]
    }

    Product {
        name: "Demo 05"
        targetName: "demo05"
        condition: true

        type: "application"
        consoleApplication: true
        destinationDirectory: "./"

        Depends { name: "cpp" }
        Depends { name: "cppstdlib" }
        Depends { name: "SharedLib" }
        Depends { name: "Yaml" }
        Depends { name: "Qt"; submodules: ["core"] }

        cpp.defines: project.cppDefines
        cpp.cxxFlags: project.cxxFlags
        cpp.cxxLanguageVersion: project.cxxLanguageVersion

        //cpp.includePaths: [
        //]

        cpp.dynamicLibraries: [
            "pthread",
        ]

        Group {
            name: "resources"
            files: "src/demo05/demo05.qrc"
        }

        files: [
            "src/demo05/demo05.cpp",
            "src/demo05/module1.cpp",
            "src/demo05/module2.cpp",
        ]
    }

}
