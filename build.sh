cd bot/
echo =========================
echo Compiling
scons
echo Compilation finished
echo =========================

cd test/
echo Running unittest
./test
echo Unittest finished sucessfully