<?php

include 'connect.php';
$_tmp=$_GET['temp'];

$ipaddr = $_SERVER['REMOTE_ADDR'];

// Create connection
$conn = mysqli_connect($servername, $username, $password, $dbname);
// Check connection
if (!$conn) {
  die("Connection failed: " . mysqli_connect_error());
}


$sql = "INSERT INTO iot_ders2 (sicaklik, ip_addr, zaman) VALUES ($_tmp, '".$ipaddr."', NOW())";

echo $sql;
echo "<br>";


if (mysqli_query($conn, $sql)) {
  echo "New record created successfully";
} else {
  echo "Error: " . $sql . "<br>" . mysqli_error($conn);
}

mysqli_close($conn);
?>