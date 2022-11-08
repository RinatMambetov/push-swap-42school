# p=`pbpaste`
# git clone $p ps
cp -r ../ps .
cd ps
norminette
make
make bonus
cd ..
bash push_swap_tester/tester.sh ps 3 10
bash push_swap_tester/tester.sh ps 5 10
bash push_swap_tester/tester.sh ps 100 10
bash push_swap_tester/tester.sh ps 500 5
cd ps
cp ../push_swap_visualizer/pyviz.py .
python3 pyviz.py `ruby -e "puts (-250..250).to_a.shuffle.join(' ')"`
cd ..
