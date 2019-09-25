<?php
//    require 'log_reg/server.php';
if (!isset($_SESSION))
{
    session_start();
}
?>
<div>
    <div class="head_class">
        <a href="index.php" id="header_text">
            Кинотеатр "Кинотеатр"
        </a>
    </div>

    <?php
    include('connection.php');
    $link = mysqli_connect($host, $user, $password, $database)
    or die("Connection error header.php" . mysqli_error($link));

    if(isset($_SESSION['username']))
    {
        $query = mysqli_query($link, "SELECT * FROM user WHERE idUser = '".intval($_SESSION['idUser'])."' LIMIT 1");
        $userdata = mysqli_fetch_assoc($query);

        //echo "<br><p style='float: right;'>".$userdata['Username']."</p>";
        echo "
        <form method=\"post\" >
            <button type=\"submit\" class=\"log_button\" name=\"exitBtn\" value='logout'>
                Выход
            </button>
        </form>
        ";
        if (isset($_POST['exitBtn']))
        {
            session_destroy();
            header('Location: index.php');
        }
    }
    else
    {
        echo "
            <form method=\"post\">
                <button type=\"submit\" formaction=\"log_reg/authorization/login.php\" class=\"log_button\" name=\"loginBtn\" value=\"login\">
                    Вход
                </button>
                <button type=\"submit\" formaction=\"log_reg/registration/register.php\" class=\"log_button\" name=\"reg\" value=\"reg1\">
                    Регистрация
                </button>
            </form>";
    }
        ?>


    <div class="clear">

    </div>
</div>

