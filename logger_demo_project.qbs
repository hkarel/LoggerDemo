import qbs
import "demo_base.qbs" as DemoBase

Project {
    name: "LoggerDemo (Project)"

    minimumQbsVersion: "1.20.0"
    qbsSearchPaths: ["qbs"]

    property var cppDefines: {
        var def = [];
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
    property string cxxLanguageVersion: "c++17"

    references: [
        "src/shared/shared.qbs",
        "src/yaml/yaml.qbs",
    ]


    DemoBase {
        name: "Demo 01"
        targetName: "demo01"
        condition: true

        files: baseFiles.concat([
            "src/demo01/demo01.cpp",
        ])
    }

    DemoBase {
        name: "Demo 02"
        targetName: "demo02"
        condition: true

        files: baseFiles.concat([
            "src/demo02/demo02.cpp",
        ])
    }

    DemoBase {
        name: "Demo 03"
        targetName: "demo03"
        condition: true

        files: baseFiles.concat([
            "src/demo03/demo03.cpp",
        ])
    }

    DemoBase {
        name: "Demo 04"
        targetName: "demo04"
        condition: true

        files: baseFiles.concat([
            "src/demo04/demo04.cpp",
            "src/demo04/module1.cpp",
            "src/demo04/module2.cpp",
        ])
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

    DemoBase {
        name: "Demo 06"
        targetName: "demo06"
        condition: true

        files: baseFiles.concat([
            "src/demo06/demo06.cpp",
        ])
    }

    DemoBase {
        name: "Demo 07"
        targetName: "demo07"
        condition: true

        files: baseFiles.concat([
            "src/demo07/demo07.cpp",
        ])
    }

}
