--set minimal version: 2.2.6
set_xmakever("2.2.6")

-- add modes: debug and release 
add_rules("mode.debug", "mode.release")

set_languages("c99", "cxx17")

option("pthread")
    set_default(true)
    add_links("pthread")
    if not is_host("windows") then
        add_linkdirs("/usr/local/lib")
    else
        add_linkdirs("C:/msys64/mingw64/lib")
    end
option_end()

-- add target
target("Networking-TS-Example")

    -- set kind
    set_kind("binary")

    -- add files
	add_files("examples/networking-stream.cpp")
	add_includedirs("include")
	
	-- add libs options
	add_options("pthread")
	if(is_host("windows")) then
        add_ldflags("-lws2_32", {force=true})
    end

--
-- FAQ
--
-- You can enter the project directory firstly before building project.
--   
--   $ cd projectdir
-- 
-- 1. How to build project?
--   
--   $ xmake
--
-- 2. How to configure project?
--
--   $ xmake f -p [macosx|linux|iphoneos ..] -a [x86_64|i386|arm64 ..] -m [debug|release]
--
-- 3. Where is the build output directory?
--
--   The default output directory is `./build` and you can configure the output directory.
--
--   $ xmake f -o outputdir
--   $ xmake
--
-- 4. How to run and debug target after building project?
--
--   $ xmake run [targetname]
--   $ xmake run -d [targetname]
--
-- 5. How to install target to the system directory or other output directory?
--
--   $ xmake install 
--   $ xmake install -o installdir
--
-- 6. Add some frequently-used compilation flags in xmake.lua
--
-- @code 
--    -- add macro defination
--    add_defines("NDEBUG", "_GNU_SOURCE=1")
--
--    -- set warning all as error
--    set_warnings("all", "error")
--
--    -- set language: c99, c++11
--    set_languages("c99", "cxx11")
--
--    -- set optimization: none, faster, fastest, smallest 
--    set_optimize("fastest")
--    
--    -- add include search directories
--    add_includedirs("/usr/include", "/usr/local/include")
--
--    -- add link libraries and search directories
--    add_links("tbox", "z", "pthread")
--    add_linkdirs("/usr/local/lib", "/usr/lib")
--
--    -- add compilation and link flags
--    add_cxflags("-stdnolib", "-fno-strict-aliasing")
--    add_ldflags("-L/usr/local/lib", "-lpthread", {force = true})
--
-- @endcode
--
-- 7. If you want to known more usage about xmake, please see http://xmake.io/#/home
--
