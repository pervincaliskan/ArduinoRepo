<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "iot_lisans";

// Create connection
$conn = mysqli_connect($servername, $username, $password, $dbname);
// Check connection
if (!$conn) {
  die("Connection failed: " . mysqli_connect_error());
}

// $sql = "INSERT INTO MyGuests (firstname, lastname, email)
// VALUES ('John', 'Doe', 'john@example.com')";

$sql = "INSERT INTO iot_ders1 (name, surname, age, height)
VALUES ('Johnt', 'Doet', '30', '179')";

echo $sql;
echo "<br>";


if (mysqli_query($conn, $sql)) {
  echo "New record created successfully";
} else {
  echo "Error: " . $sql . "<br>" . mysqli_error($conn);
}

mysqli_close($conn);
?>