<!--
  Licensed to the Apache Software Foundation (ASF) under one or more
  contributor license agreements.  See the NOTICE file distributed with
  this work for additional information regarding copyright ownership.
  The ASF licenses this file to You under the Apache License, Version 2.0
  (the "License"); you may not use this file except in compliance with
  the License.  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
-->
<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%
	String path = request.getContextPath();
	String basePath = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort()
			+ path + "/";
	System.out.println(basePath);
%>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>YJIOT ajax WebSocket TEST</title>
<script type="text/javascript" src="<%=basePath%>js/jquery-2.1.3.js"></script>

<script type="text/javascript">
	function test() {
		$.ajax({
			type : 'POST',
			crossDomain : true,
			contentType : 'application/json',
			url : 'http://io.bjyjyz.com:8088/YJIOT/client/register',
			data : "{\"openid\":\"sssss\",\"tel\":\"13439966768\"}",
			dataType : 'json',
			success : function(result) {
				alert(JSON.stringify(result));
			},
			error : function(XMLHttpRequest, textStatus, errorThrown) {
				alert(err);
			}
		});

	}
	function test1() {
		$.ajax({
			type : 'POST',
			crossDomain : true,
			contentType : 'application/json',
			url : 'http://app.techstar.com.cn/YJIOT/client/getDevInfo?deviceMac=C89346530883',
			headers : {
				Accept : 'application/json; charset=utf-8',
				Authorization : 'JWT eyJ0eXAiOiJqd3QiLCJhbGciOiJIUzI1NiJ9.eyJkZXZpY2VpZCI6IjZlNmE2ZGU4LTE5MmEtNGYxOS1iMWY5LWUzMzQwZjJiZTYwNCIsImV4cCI6MTUwNTgwMDExNTY2MSwib3JpZ19pYXQiOjE1MDU3MTM3MTU2NjEsInVzZXJfaWQiOjM1NDI5fQ.st39GPxlqCASJv8ezF73xLDUeMFBwe-T2cx5FlCr7ZM'
			},
			dataType : 'json',
			success : function(result) {
				alert(JSON.stringify(result));
			},
			error : function(XMLHttpRequest, textStatus, errorThrown) {
				alert(err);
			}
		});

	}

	var jsonObj = {
		"username" : "herolizhen123",
		"password" : "123123"
	};

	function test2() {
		$.ajax({
			type : 'POST',
			crossDomain : true,
			contentType : 'application/json',
			url : 'http://io.bjyjyz.com:8088/YJIOT/power/login',
			data : JSON.stringify(jsonObj),
			dataType : 'json',
			success : function(result) {
				alert(JSON.stringify(result));
			},
			error : function(XMLHttpRequest, textStatus, errorThrown) {
				alert(err);
			}
		});

	}


	function test3() {
		var settings = {
			"crossDomain" : true,
			"url" : "http://127.0.0.1/YJIOT/power/selApp",
			"method" : "POST",
			"headers" : {
				"content-type" : "application/json",
				"authorization" : "eyJ0eXAiOiJqd3QiLCJhbGciOiJIUzI1NiJ9.eyJhcHBfaWQiOiJjNWZiZTNhYS1iM2E0LTExZTctOWJhZjAwMTYzZTEyMGQ5OCIsImRldmljZV9pZCI6bnVsbCwiZXhwIjoxNTEwNzM5NjM5ODc2LCJvcmlnX2lhdCI6MTUxMDczMzYzOTg3NiwidXNlcl9pZCI6Imhlcm9saXpoZW4ifQ.aRX_W2Ezr8k9MJhdiAMXDDyyTMeFRzYHsjjlipCzNTI"
			},
			"data" : "{\n\t\"appId\": \"b373781e-3c01-4f5d-8e12-7cb6edf56943\"\n}"
		}

		$.ajax(settings).done(function(response) {
			alert(JSON.stringify(response));
			console.log(response);
		});
	}
</script>
</head>
<body>

	<form id='test'>
		<input type="button" value="AJAX测试" id="btndel" onclick="test()" /> <input
			type="button" value="AJAX测试1" id="btndel1" onclick="test1()" /> <input
			type="button" value="登录测试" id="btndel1" onclick="test2()" /> <input
			type="button" value="验证码" id="btndel1" onclick="test3()" />
	</form>

</body>
</html>