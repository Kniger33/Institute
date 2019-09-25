<html lang="en">
<head>
    <meta charset="utf-8">
    <title><?=$title?></title>
    <link rel="stylesheet" type="text/css" href="css/style.css" >
</head>

<body>
<?php
    include ("parts/header.phtml");
    include ("parts/navigation.phtml");
?>

<div class="content_class"><?=$component?></div>

<?php    
    include ("parts/footer.phtml");
?>

</body>
</html>