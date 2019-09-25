<?php
//    if(session_id() == '')
//    {
//        session_start();
//    }
    if (!isset($_SESSION))
    {
        session_start();
    }

    $emailRE = '(^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$)';
    $username = "";
    $email = "";
    $errors = array();

    //connect to db
    //include "../connection.php";
    $link = mysqli_connect('localhost', 'root', '1234', 'web')
    or die("Connect error ".mysqli_error($link));

    // if the register button is clicked
    if (isset($_POST['register']))
    {
        $username = mysqli_real_escape_string($link, $_POST['username']);
        $email = mysqli_real_escape_string($link, $_POST['email']);
        $password_1 = mysqli_real_escape_string($link, $_POST['password_1']);
        $password_2 = mysqli_real_escape_string($link, $_POST['password_2']);

        //ensure that the form fields are filled properly
        if (empty($username))
        {
            array_push($errors, "Username is required");
        }
        if (empty($email))
        {
            array_push($errors, "Email is required");
        }
        if(preg_match($emailRE, $email) == 0)
        {
            array_push($errors, "Invalid email");
        }
        if (empty($password_1))
        {
            array_push($errors, "Password is required");
        }

        if($password_1 != $password_2)
        {
            array_push($errors, "The two passwords do not match");
        }

        //if there are no errors, save user to db
        if(count($errors) == 0)
        {
            $passwordMD5 = md5($password_1); //encrypt password before storing in db (security)

            $query = "INSERT INTO user (Username, Email, Password, Root)
                        VALUES ('$username', '$email', '$passwordMD5', 'user')";

            mysqli_query($link, $query);

            $_SESSION['username'] = $username;

            $queryLogin = "SELECT * FROM user WHERE Username = '$username' AND Password = '$passwordMD5'";
            $result = mysqli_query($link, $queryLogin);
            $row = mysqli_fetch_array($result);
            $_SESSION['idUser'] = $row['idUser'];
            $_SESSION['root'] = $row['Root'];
//
//            $_SESSION['success'] = "Yoa are now logged in";
            header('Location: /index.php');
        }
    }

    //log user in from login page
    if(isset($_POST['login']))
    {
        $username = mysqli_real_escape_string($link, $_POST['username']);
        $password = mysqli_real_escape_string($link, $_POST['password']);

        //ensure that the form fields are filled properly
        if (empty($username))
        {
            array_push($errors, "Username is required");
        }
        if (empty($password))
        {
            array_push($errors, "Password is required");
        }

        if(count($errors) == 0)
        {
            $password = md5($password); // encrypt password before comparing with thar from db

            $queryLogin = "SELECT * FROM user WHERE Username = '$username' AND Password = '$password'";
            $result = mysqli_query($link, $queryLogin);
            if(mysqli_num_rows($result) == 1)
            {
                //log user in
                $row = mysqli_fetch_array($result);
                $_SESSION['username'] = $username;
                $_SESSION['idUser'] = $row['idUser'];
                $_SESSION['root'] = $row['Root'];
                $_SESSION['success'] = "Yoa are now logged in";
                header('Location: /index.php');
            }
            else
            {
                array_push($errors, "Wrong username/password combination");
            }
        }
    }

    //logout
    if (isset($_POST['exitBtn']))
    {
        session_destroy();
        unset($_SESSION['username']);
        unset($_SESSION['idUser']);
        unset($_SESSION['root']);
        header('Location: /index.php');
    }

?>