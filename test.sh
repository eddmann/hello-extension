CODE=$(cat <<EOF
echo hello_world() . PHP_EOL;
echo hello('JoE') . PHP_EOL;
echo hello('JoE', true) . PHP_EOL;
echo hello('JoE', false) . PHP_EOL;
EOF)
$HOME/php/bin/phpize --clean
$HOME/php/bin/phpize
./configure --with-php-config=$HOME/php/bin/php-config
make && make install && clear
$HOME/php/bin/php -dextension=hello.so -r "$CODE"