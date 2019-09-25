<?php
// MYSQL
class FITNESSTIME
{
    var $dblogin = "root"; // логин
    var $dbpass = ""; // пароль
    var $db = "fitnesstime"; // название бд
    var $dbhost="127.0.0.1:3306"; // хост, по которому подключаемся

    var $link;
    var $query;
    var $err;
    var $result;
    var $data;
    var $fetch;

    function  __construct()
    {
        self::connect();
    }

    function connect() {
        $this->link = mysqli_connect($this->dbhost, $this->dblogin, $this->dbpass, $this->db) or die("Ошибка " . mysqli_error($this->link));
        mysqli_select_db($this->link, $this->db);
        mysqli_query( $this->link, 'SET NAMES utf8');
    }

    function close() {
        mysqli_close($this->link);
    }

    function run($query) {
        $this->query = $query;
        $this->result = mysqli_query($this->link,$this->query);
        $this->err = mysqli_error($this->link);
    }

    function row() {
        $this->data = mysqli_fetch_assoc($this->result);
    }

    function fetch() {
        while ($this->data = mysqli_fetch_assoc($this->result)) {
        $this->fetch = $this->data;
        return $this->fetch;
        }
    }
    
    function stop() {
        unset($this->data);
        unset($this->result);
        unset($this->fetch);
        unset($this->err);
        unset($this->query);
    }
}
