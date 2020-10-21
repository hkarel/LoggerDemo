import qbs
import QbsUtl

Product {
    name: "SharedLib"
    targetName: "shared"

    type: "staticlibrary"

    Depends { name: "cpp" }
    Depends { name: "cppstdlib" }
    Depends { name: "Yaml" }
    Depends { name: "Qt"; submodules: ["core", "network"]; required: false}

    moduleProviders.Qt.qmakeFilePaths: "/invalid"
    condition: Qt.core.present

    cpp.defines: project.cppDefines
    cpp.cxxFlags: project.cxxFlags //.concat(["-fPIC"])
    cpp.cxxLanguageVersion: project.cxxLanguageVersion

    property var exportIncludePaths: [
        "./",
        "./shared",
    ]
    cpp.includePaths: exportIncludePaths;

    // Эта декларация нужна для подавления Qt warning-ов
    cpp.systemIncludePaths: Qt.core.cpp.includePaths

    cpp.rpaths: QbsUtl.concatPaths(
        cppstdlib.path,
        "$ORIGIN/../lib"
    )

    cpp.dynamicLibraries: [
        "pthread",
    ]

    files: [
        "shared/config/appl_conf.cpp",
        "shared/config/appl_conf.h",
        "shared/config/logger_conf.cpp",
        "shared/config/logger_conf.h",
        "shared/config/yaml_config.cpp",
        "shared/config/yaml_config.h",
        "shared/logger/config.cpp",
        "shared/logger/config.h",
        "shared/logger/format.h",
        "shared/logger/logger.cpp",
        "shared/logger/logger.h",
        "shared/qt/logger_operators.cpp",
        "shared/qt/logger_operators.h",
        "shared/thread/thread_base.cpp",
        "shared/thread/thread_base.h",
        "shared/thread/thread_pool.cpp",
        "shared/thread/thread_pool.h",
        "shared/thread/thread_utils.cpp",
        "shared/thread/thread_utils.h",
        "shared/break_point.h",
        "shared/clife_alloc.h",
        "shared/clife_base.h",
        "shared/clife_ptr.h",
        "shared/container_ptr.h",
        "shared/list.h",
        "shared/prog_abort.cpp",
        "shared/prog_abort.h",
        "shared/safe_singleton.h",
        "shared/simple_ptr.h",
        "shared/simple_timer.h",
        "shared/spin_locker.h",
        "shared/steady_timer.h",
        "shared/type_name.h",
        "shared/utils.cpp",
        "shared/utils.h",
    ]

    Export {
        Depends { name: "cpp" }
        cpp.includePaths: product.exportIncludePaths
    }
}
