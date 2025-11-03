<?php
header('Content-Type: ' . "application/json");

$postData="";
$data="";

require_once($_SERVER["DOCUMENT_ROOT"]."/lk/connect.php"); 

//require_once($_SERVER["DOCUMENT_ROOT"]."/lk/functions.php"); 

global $file;
$file = "/save-eqpt.php";

global $str;

try
{
	// ----------------------------------------------------
	//	МОЖЕТ ПОКАЗАТЬСЯ ЧТО ВАЖНО для \\ его надо еще разок задублировать \\\\ 
	// - херня не надо !
	//	str_replace('\\', '\\\\'
	// просто достаточно принять \" \/ \\ и все будет ОК
	// далее при записи в MySql надо экранировать ' \ "
	// ------------------------------------------------------*/
	
	
	$postData = file_get_contents('php://input').PHP_EOL;;
	
	
	if( $postData === false )
	{
		echo "{\"result\" : 1 , \"description\" : \"error file_get_contents\"}"; 
		logg("256 file_get_contents");
		exitSql2();
	}
	else
	{
		
	}
	//var_dump($postData);
} 
catch (Exception $e) 
{
    echo "{\"result\":2 , \"description\" : \"Exception file_get_contents\"}";
	logg("256 Exception file_get_contents"); 
	exitSql2();
}

logg("in : ".$postData);

try
{
	
		//postData: {"qqqq":"\u005C"}
		$data = json_decode( $postData , true );//, JSON_UNESCAPED_SLASHES);
		
		// Если true, объекты JSON будут возвращены как ассоциативные массивы (array); 
		// если false, объекты JSON будут возвращены как объекты (object).
		
		// НЕ ИСПОЛЬЗУЙ JSON_THROW_ON_ERROR - ХЕРНЯ КАКАЯ-ТО
		
		// для json_encode
		// JSON_UNESCAPED_SLASHES Не экранировать /);
		// JSON_UNESCAPED_UNICODE Не кодировать многобайтовые символы Unicode (по умолчанию они кодируются как \uXXXX)
} 
catch (Exception $e) 
{
    echo "{\"result\":3 , \"description\" : \"Exception json_decode\"}";
	logg("256 Exception json_decode");
	exitSql2();
}

if( $data === null) // РАБОТАЕТ - ЕДИНСТВЕННЫЙ ВАРИАНТ
{
    echo "{\"result\":3 , \"description\" : \"Некорректные данные с ПК, возможно пора обновить программу.\"}";
	logg("!!! ERROR !!! вход на сервер с дефектным json пакетом  25534553454 postData = $postData");
	
	if ( my_php_mailer("вход на сервер с дефектным json пакетом ($file)" , "проблема в json_decode!" , "p@kkmspb.ru") == -1)
	{
		logg("письмо об ошибке НЕ отправлено");
	}
	
	exitSql2();
}


if( ! is_array( $data ) )
{
	logg( "json_decode FAILED postData:".$postData);
	echo "{\"result\":3 , \"description\" : \"json_decode FAILED postData\"}";
	exitSql2();
}
//logg( "postData:".$postData );

//-----------------------------------------------

global $progHash;
$progHash="";


if (! array_key_exists('progHash', $data) ) 
{
    echo "{\"result\":5 , \"description\" : \"uncorrect field progHash\"}";
	logg("256 uncorrect field progHash");
	exitSql2();
}

$progHash = trim($data["progHash"]);
//-----------------------------------------------

if (!array_key_exists('typ', $data)) 
{
    echo "{\"result\":5 , \"description\" : \"not exist field typ\"}";
	logg("256 not exist field typ" , $typ);
	exitSql2();
}
else if (! array_key_exists('turnedOn', $data) ) 
{
    echo "{\"result\":5 , \"description\" : \"uncorrect field turnedOn\"}";
	logg("256 uncorrect field turnedOn" , $turnedOn);
	exitSql2();
}
else if (!array_key_exists('sId', $data)) 
{
    echo "{\"result\":4 , \"description\" : \"not exist field sId\"}";
	logg("256 not exist field sId" , $sId);
	exitSql2();
}
else if (!array_key_exists('gr', $data)) 
{
    echo "{\"result\":5 , \"description\" : \"not exist field gr\"}";
	logg("256 not exist field gr" , $gr);
	exitSql2();
}
else if (! array_key_exists('json', $data)) 
{
    echo "{\"result\":5 , \"description\" : \"not exist field json\"}";
	logg("256 not exist field json" , $json);
	exitSql2();
}
else if (! array_key_exists('special', $data)) 
{
    echo "{\"result\":5 , \"description\" : \"not exist field special\"}";
	logg("256 not exist field special" , $special);
	exitSql2();
}

//$progHash = $data["progHash"];

//$tel 		= trim($data["tel"]);
$sId 		= trim($data["sId"]);
$turnedOn 	= trim($data["turnedOn"]);
$gr 		= trim($data["gr"]);
$typ 		= trim($data["typ"]);
$inn 		= trim($data["special"]["inn"]);
$org_name 	= trim($data["special"]["org_name"]);
$addr 		= trim($data["special"]["addr"]);

$eqptHash1   = trim($data["eqptHash"]); // для нового оборудования отстутсвует

$json 		= $data["json"];


//logg("dir:".$json["dir"]);

//var_dump($json);
//echo "json : ".$json."\n\n";
// ---------------------------------
//   
// ---------------------------------

global $mysqli2, $mysql_dbname2 , $gl_supersecret_hash_padding_256 , $gl_supersecret_Email_confirm_256;

//---------------------------------------------------------------------------
//     			находим progHash
//---------------------------------------------------------------------------

$sql1 = "SELECT * FROM `prog` WHERE `progHash`='$progHash' LIMIT 4";

//loggUser("userPressConfirmBtn ".$sql1, $email);

if( ! $resProg = $mysqli2->query($sql1) )
{
	srvError(75675476355965 , $sql1." ".$mysqli2->error."" ) ;
}


if( ! $prog = $resProg->fetch_assoc()) 	
{
	srvError(846387896758895, $sql1." ".$mysqli2->error."" ) ;
}
	
$json1 = json_encode( $json , JSON_UNESCAPED_SLASHES ); // , JSON_UNESCAPED_UNICODE);	
logg("json1 $json1" );

//echo "json1=$json1";


//---------------------------------------------------------------------------
//     			находим drv_eqpt
//---------------------------------------------------------------------------


global $progVersion, $gl_sault_eqpt;
global $email;
$email=$prog["email"];
$progVersion = $prog["progVersion"];
	
$reinitialization = 0; //  это маркер, что нашли в базе другой таклой же sId и переключаем ответ на него

if( $eqptHash1 == "" )  // новое оборудование или вновь подключаемое
{
	logg("eqptHash1 == '' новое оборудование или не подключенное");
	
	/*
		при добавлении "новой" кассы может оказаться, что она уже была добавлена и использовалась ранее 
		(sId : UNIQUE) тогда мы не создаем новой экземпляр оборудования
		
		ищем по sId оборудование !
	*/
	
	$sql1 = "SELECT * FROM `drv_eqpt` WHERE `prog_id` = ".$prog["progId"]." AND `sId`='".ekran_mysql($sId)."'";
	
	if( ! $res1 = $mysqli2->query($sql1) )
	{
		srvError(57657567465766 , $sql1." ".$mysqli2->error."" ) ;
	}	
	
	if( ! $eqpt_sId = $res1->fetch_assoc()) 
	{
		$now=date("Y-m-d H:i:s").microtime();
		
		$ip = $_SERVER['REMOTE_ADDR'];

		$eqptHash1 = md5($now.$ip.$email.$gl_sault_eqpt);
		
		logg("новое подключение оборудования, сгенерирован новый eqptHash='$eqptHash1'  $email");
		
		
		$sql3 = "INSERT INTO  `drv_eqpt` 
		(`prog_id` , `sId` , `typ` ,  `turnedOn` , `gr` , `inn` , `org_name` , `addr` , `json`, `hidden`, `email`, `progVersion`, `hash`)
		VALUES (".$prog["progId"]." , '".ekran_mysql($sId)."' , $typ ,  $turnedOn , $gr, '$inn', '".ekran_mysql($org_name)."', '".ekran_mysql($addr)."' ,'".ekran_mysql($json1)."' ,'0' , '$email' , '$progVersion', '$eqptHash1')";

		//`hash` устанавливается один раз при первом подключении оборудования (IF(hash IS NULL,)
		// далее sId UNIQE не даст создать еще одну строчку оборудования с таким же sId

		//echo "\nsql3=".$sql3;
		logg("$sql3" ) ;
		//loggUser("userPressConfirmBtn ".$sql1, $email);

		if( ! $res3 = $mysqli2->query($sql3) )
		{
			echo $sql3;
			srvError(876587565867565 , $sql3." ".$mysqli2->error."" ) ;
		}

		$insertId = $mysqli2->insert_id;
			
		if( $insertId > 0) 
		{
			logg("mysqli2->insert_id:".$insertId);
		}
		else
		{
			logg("mysqli2->insert_id:".$insertId);
			Err_update( $sId , $sqlNewE, "3243243242343");
		}
		

		$sqlNewE = "SELECT * FROM `drv_eqpt` WHERE pri = ".$insertId."";
		
		if( ! $resNew = $mysqli2->query($sqlNewE) )
		{
			srvError(536353356546 , $sqlNewE." ".$mysqli2->error."" ) ;
		}	
		
		if( ! $eqptNew = $resNew->fetch_assoc()) 
		{
			Err_update( $sId , $sqlNewE , "689397846858");
		}
		
		/*
			даже если это был update все-равно insert_id вернется
			и это хорошо , т.к. новая строка оборудования в таблице не появится
			if( $eqptNew["hash"] != $eqptHash ) так не делаем
			{
				Err_update( $sId , $sqlNewE);
			}
		*/

		
		OK_update( $sId , $insertId , $eqptNew["hash"] , $reinitialization);  //!!!!
		
	}
	else // уже ранее была подключена (см. sId)
	{
		if( $eqpt_sId["turnedOn"] == 1 && $turnedOn == 1) // если она подключена, второй раз не подключить
		{
			Err_update( $sId , $sql1 , "Оборудование '".ekran_mysql($sId)."' уже подключено (проверьте в списке)");
		}
		
		
		$eqptHash2 = $eqpt_sId["hash"];
		
		// уже ранее подключенное отборудование
	}
}	
else
{	
	$eqptHash2 = $eqptHash1 ;
	
	logg("eqptHash1 != '' ");
}

/*
	надо проверить один случай:
	что ты меняешь sId, но он уже есть у другого оболудования 
	например scanner COM11, подключаем на порт COM2, а scanner COM2 уже тоже есть и подключен
*/

logg("уже ранее подключенное оборудование $eqptHash2");

//----------------------------------------------------------

/*
		находим оборудование по eqptHash2
*/

$sql2 = "SELECT * FROM `drv_eqpt` WHERE `hash`='".$eqptHash2."'";

if( ! $res2 = $mysqli2->query($sql2) )
{
	srvError(793856785468545 , $sql2." ".$mysqli2->error."" ) ;
}	

if(  $eqpt2 = $res2->fetch_assoc()) 
{
	// защита от "случайного" совпадения progHash, на всякий случай ...
	
	if( $eqpt2["prog_id"] != $prog["progId"] )
	{
		logg("45434532452345234543253454");
		Err_update( $sId , $sql2 , "Сбой при подключении оборудования (353454) ".ekran_mysql($sId)." ".$eqptHash2);
	}
}

//----------------------------------------------------------


if( $eqpt2["sId"] != $sId ) // наш sId 
{
	logg("внимание меняется sId '".$eqpt2["sId"]."' на '".$sId."'" );
	
	// а если такой sId уже был у другого экземпляра оборудования? что делать? Надо выбирать его. 
}



if( $turnedOn == 1 ) // только при подключении
{
	logg("подключение оборудования '".$sId."'");
	
	/*
		именно подключение оборудование является особенным с точки зрения логики алгоритма
	*/
	
	logg("ищем другое оборудование с таким же sId '".$sId."' hash <>".$eqptHash2);
	
	$resOther = "SELECT * FROM `drv_eqpt` WHERE 
	`prog_id` = ".$prog["progId"]." 
	AND `sId` = '".ekran_mysql($sId)."'  
	AND `hash` <> '".$eqptHash2."'" ; // AND `turnedOn` = 1
	


	if( ! $resOtherE = $mysqli2->query($resOther) )
		srvError(3648758476854 , $resOther." ".$mysqli2->error."" ) ;

	
	if( $eqptAllready = $resOtherE->fetch_assoc()) 
	{
		logg("нашли другое оборудование с таким же sId ".$sId);
		/*
			тут суть в том, что sId уже может быть в базе данных (у скрытого оборудования например)
			и нам не удастся сделать update на принятом sId
			поэтому сделаем update на другом экземпляре
			подключим его и и вернем его параметры
		*/
		
		if( $eqptAllready["turnedOn"] == 1 )  // 
		{
			Err_update( $sId , $resOther, "Оборудование :\n\n'".ekran_mysql($sId)."'\n\nуже подключено,\n\n(проверьте список подключенного оборудования)");
		}
		
		
		//logg("turnedOn");
		
		if( $eqptHash1 != $eqptHash2)
		{
			//--------------------------------------------------------------------
			// на всякий случай сразу скроем исходный
			//--------------------------------------------------------------------
			
			$sql3 = "UPDATE `$mysql_dbname2`.`drv_eqpt` 
			 SET  `hidden`='1', `turnedOn`='0'
			 WHERE  `prog_id` = ".$prog["progId"]." AND `hash` = '".$eqptHash1."'	";
			 
			logg("2222222222222 $sql3" ) ;

			if( ! $res3 = $mysqli2->query($sql3) )
			{
				echo $sql3;
				srvError(83454353245454 , $sql3." ".$mysqli2->error."" ) ;
			}
			
			logg("скрыли исходный экземпляр  ".$sId. " ".$progHash1 );
			
			//--------------------------------------------------------------------
			// на всякий случай сразу его разархивируем и подключаем
			//--------------------------------------------------------------------
			
			$sql3 = "UPDATE `$mysql_dbname2`.`drv_eqpt` 
			 SET  `hidden`='0', `turnedOn`='1'
			 WHERE  `prog_id` = ".$prog["progId"]." AND  `hash` = '".$eqptAllready["hash"]."'	";
			 
			logg("2222222222222 $sql3" ) ;

			if( ! $res3 = $mysqli2->query($sql3) )
			{
				echo $sql3;
				srvError(83454353245454 , $sql3." ".$mysqli2->error."" ) ;
			}
			
			logg("показали другой экземпляр  ".$sId. " ".$eqptAllready["hash"] );
			
			//$eqptHash2 = $eqptAllready["hash"]; // заменили eqptHash с найденного другого sId
			
		}
	
		$reinitialization = 1;
		logg("reinitialization = 1;" );
	}
	else
	{
		logg("не нашли другое оборудование с таким же sId '".$sId."'");
	}
}
else
{
	logg("отключение оборудования sId '".$sId."'");
}


// ------------------------------------------------------------------------
// ниже всегда завершаем только update
// внимание: `hidden`='0' (тут всегда)
// `sId`='".ekran_mysql($sId)."' , никогда здесь не меняем sId 
// он один раз только при создании экземляра
// ------------------------------------------------------------------------
	
$sql3 = "UPDATE `$mysql_dbname2`.`drv_eqpt` 
SET `typ`=$typ ,  `turnedOn`=$turnedOn , `gr`=$gr , `inn`='$inn',
`org_name`='".ekran_mysql($org_name)."', `addr` = '".ekran_mysql($addr)."' , 
`json`='".ekran_mysql($json1)."', `hidden`='0', `email` ='$email' , `progVersion`='$progVersion' 
 WHERE `prog_id` = ".$prog["progId"]." AND `hash` = '".$eqptHash2."'	";

//`hash` устанавливается один раз при первом подключении оборудования (IF(hash IS NULL,)
// далее sId UNIQE не даст создать еще одну строчку оборудования с таким же sId

//echo "\nsql3=".$sql3;
logg("'".$sId."' `turnedOn`=$turnedOn \n $sql3" ) ;
//loggUser("userPressConfirmBtn ".$sql1, $email);

if( ! $res3 = $mysqli2->query($sql3) )
{
	//echo $sql3;
	srvError(83454353245454 , $sql3." ".$mysqli2->error."" ) ;
}

// $insertId = $mysqli2->insert_id; при UPDATE = 0

OK_update( $sId , $eqpt2["pri"], $eqptHash2 , $reinitialization);  //!!!!



srvError(7898973665 , $mysqli2->error."" ) ;

exit;


function Err_update( $sId , $sql, $displayToUser="")
{
	global $progHash;
	
	if($displayToUser !="")
		$displayToUser = ", \"displayToUser\":\"$displayToUser\"";
	
	echo "{\"result\":102, \"act\":\"err\", \"description\":\"not saved\" , \"sId\" : \"$sId\" $displayToUser}";
		
	logg("Error insert or update device settings '".$sId."' (pri =$pri) \n(sql=$sql)");
	
	exitSql2();
}

function OK_update( $sId , $pri, $hash , $reinitialization = 0)
{
	global $progHash;
	
	$flag="";
	if( $reinitialization == 1 )
		$flag = ", \"retrain\" : \"$hash\"";
		
	
	echo "{\"result\":0, \"act\":\"OK\", \"description\":\"saved\" , \"sId\" : \"$sId\" , \"pri\" : \"$pri\", \"hash\":\"$hash\" $flag}";
		
	logg("OK '$sId' сохранение настроек $flag\n  (pri =$pri) hash:$hash ");
	
	exitSql2();
}

?>
