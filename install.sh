./helpers/addString.rc WORKING_DIR $(pwd)
make
echo "alias zeno=$(pwd)/zeno" >> ~/.bashrc
source ~/.bashrc