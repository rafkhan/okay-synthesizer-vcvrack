if [ "$#" == 0 ]; then
    cd DaisySP
    make
    cd ../OkaySynthesizer
    make
    echo "Run with 'install' to add the plugin to the rack user folder plugins"
elif [ "$1" == "help" ]; then
    echo "Run with no arguments to just build"
    echo "install   - Builds the plugins and adds them to the rack user folder plugins"
    echo "clean     - Runs make clean on DaisySP and the plugin itself"
elif [ "$1" == "install" ]; then
    cd DaisySP
    make
    cd ../OkaySynthesizer
    make install
elif [ "$1" == "clean" ]; then
    cd DaisySP
    make clean
    cd ../OkaySynthesizer
    make clean
fi
