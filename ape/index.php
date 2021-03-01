<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title></title>
  </head>
  <body>
    <form action="index.php" method="get">
      <input name="area" type="text" value="A">
      <input name="velocity" type="text" value="V">
      <input type="submit" name="submit" value="Submit">
    </form>

    <?php echo $_GET["area"] + $_GET["velocity"]; ?>
  </body>
</html>
