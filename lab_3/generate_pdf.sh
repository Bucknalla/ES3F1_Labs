# NOTE - This script will only work in Ubuntu & MacOS

if [[ "$OSTYPE" == "linux-gnu" ]]; then
    # Ubuntu Linux
    if [ $(dpkg-query -W -f='${Status}' librsvg2-bin 2>/dev/null | grep -c "ok installed") -eq 0 ]; then
        echo 'Error: dependencies are not installed.' 
        echo 'Installing librsvg2-bin, may require root.'
        sudo apt-get install librsvg2-bin
    fi

    if ! [ -x "$(command -v pandoc)" ]; then
        echo 'Error: pandoc is not installed.' 
        echo 'Downloading pandoc...'
        curl -L https://github.com/jgm/pandoc/releases/download/2.7.3/pandoc-2.7.3-1-amd64.deb -o resource/pandoc.deb
        sudo dpkg -i resource/pandoc.deb
    fi

elif [[ "$OSTYPE" == "darwin"* ]]; then
    # Mac OSX
    if ! brew ls --versions pandoc > /dev/null; then
        echo 'Error: pandoc is not installed.' 
        echo 'Downloading pandoc...'
        brew install librsvg pandoc
    fi
fi

if ! [ -f "resource/eisvogel.tex" ]; then
    mkdir ./resource
    echo 'Error: markdown template is not installed.' 
    echo 'Downloading template...'
    curl -L https://github.com/Wandmalfarbe/pandoc-latex-template/releases/download/v1.2.4/Eisvogel-1.2.4.tar.gz -o resource/eisvogel.tar.gz 
    tar -vxf resource/eisvogel.tar.gz -C resource/
fi

pandoc -s --self-contained README.md --listings --from markdown --template resource/eisvogel.tex -o ../pdfs/ES3F1_Lab_3.pdf 