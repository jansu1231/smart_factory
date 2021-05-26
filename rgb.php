<!DOCTYPE html>
<html>
<body>

<h1 style="text-align:center;">RGB Data</h1>

<table style="width:100%">

<?php

$conn = mysqli_connect("localhost","root","1234","smart_factory");
$result = mysqli_query($conn,"SELECT * FROM RGBdata");

echo "<th style=color:Red;> RED </th>";
echo "<th style=color:Green;> GREEN </th>";
echo "<th style=color:Blue;> BLUE </th>";
echo "<th> TOTAL </th>";

while($row = mysqli_fetch_array($result)){

echo "<tr>";
echo "<th>" . $row[0] . "</th>";
echo "<th>" . $row[1] . "</th>";
echo "<th>" . $row[2] . "</th>";
echo "<th>" . $row[3] . "</th>";
echo "</tr>";
}

mysqli_close($conn);
?>

</table>
</body>
</html>
