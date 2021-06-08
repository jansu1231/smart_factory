<!DOCTYPE html>
<html>
<body>

<head>
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<meta http-equiv="refresh" content="60;url=storage.php">
</head>

<h1 style="text-align:center;">Storage</h1>

<div class="table_layout">
<table style = width:100% border = "1">
<colgroup>
<col width="10%">
<col width="15%">
<col width="15%">
<col width="15%">
<col width="15%">
<col width="30%">
</colgroup>

<?php
$conn = mysqli_connect("localhost","root","1234","smart_factory");
$result = mysqli_query($conn, "SELECT * FROM storage");

echo "<th> NO </th>";
echo "<th style=color:Red;> RED </th>";
echo "<th style=color:Green;> GREEN </th>";
echo "<th style=color:Blue;> BLUE </th>";
echo "<th> TOTAL </th>";
echo "<th> DATE </th>";

while($row = mysqli_fetch_array($result)){

echo "<tr>";
echo "<th>" . $row[0] . "</th>";
echo "<th>" . $row[1] . "</th>";
echo "<th>" . $row[2] . "</th>";
echo "<th>" . $row[3] . "</th>";
echo "<th>" . $row[4] . "</th>";
echo "<th>" . $row[5] . "</th>";
echo "</tr>";
}

mysqli_close($conn);
?>

</table>
</div>
<style>
.button {
background-color:black;
border: none;
color: white;
padding: 15px 30px;
text-align: center;
text-decoration: none;
display: inline-block;
font-size: 16px;
margin: 4px 2px;
cursor: pointer;
float: right;
}
</style>
<div align="center">
<button><a href ="main.html">Back</a></button> 
<button><a href ="rgb.php">LIVE</a></button>
</div>
</body>
</html>
