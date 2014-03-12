HOME="/home/vagrant"
sed -i "s/^\exclude.*$/exclude=/g" /etc/yum.conf
yum groupinstall -y 'Development Tools'
cd $HOME
su vagrant -c "git clone http://git.php.net/repository/php-src.git"
cd php-src
su vagrant -c "git checkout PHP-5.5"
su vagrant -c "./buildconf"
su vagrant -c "./configure --prefix=$HOME/php --disable-cgi --disable-all --enable-debug --enable-maintainer-zts"
su vagrant -c "make && make install"