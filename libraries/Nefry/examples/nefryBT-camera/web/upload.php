<?php
if ($_SERVER["REQUEST_METHOD"] == "GET") {
    $file_list = scandir("./pic", 1);
    foreach ($file_list as $ff) { if(is_file("./pic/".$ff)) echo $ff." (".filesize("./pic/".$ff)." bytes)<br>\r\n".'<img src="./pic/'.$ff.'">'."<br>\r\n"; }
} elseif ($_SERVER["REQUEST_METHOD"] == "POST") {
    $data = file_get_contents("php://input");
    $newfile = "./pic/".date("Ymd_His").".jpg";
    file_put_contents($newfile, $data);
}
