package com.yjyz.iot.push.apicloud;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;

import org.apache.commons.codec.digest.DigestUtils;

import com.alibaba.fastjson.JSON;
import com.yjyz.iot.push.ISendPush;
import com.yjyz.iot.push.PushResult;

public class SendPush implements ISendPush {

	public PushResult send(String apiAppId, String apiAppKey, String userIds, String title, String content) {
		PushResult pushResult = new PushResult();
		try {

			URL targetUrl = new URL("https://p.apicloud.com/api/push/message");
			long t = System.currentTimeMillis();
			apiAppKey = DigestUtils.shaHex(apiAppId + "UZ" + apiAppKey + "UZ" + t) + "." + t;

			HttpURLConnection httpConnection = (HttpURLConnection) targetUrl.openConnection();
			httpConnection.setDoOutput(true);
			httpConnection.setRequestMethod("POST");
			httpConnection.setRequestProperty("Content-Type", "application/json");
			httpConnection.setRequestProperty("X-APICloud-AppId", apiAppId);
			httpConnection.setRequestProperty("X-APICloud-AppKey", apiAppKey);
			
			String input = "{\"title\":\"" + title + "\",\"content\":\"" + content
					+ "\",\"type\":2,\"platform\":0,\"userIds\":\"" + userIds + "\"}";

			OutputStream outputStream = httpConnection.getOutputStream();
			outputStream.write(input.getBytes("UTF-8"));
			outputStream.flush();

			if (httpConnection.getResponseCode() != 200) {

				pushResult.setCode(httpConnection.getResponseCode());
				pushResult.setMsg("HTTP error");
				pushResult.setStatus(0);
				return pushResult;
			}

			BufferedReader responseBuffer = new BufferedReader(
					new InputStreamReader((httpConnection.getInputStream())));

			String outputString = "";
			String output;
			while ((output = responseBuffer.readLine()) != null) {
				outputString += output;
			}
			pushResult = (PushResult) JSON.parseObject(outputString, PushResult.class);
			httpConnection.disconnect();
			return pushResult;

		} catch (MalformedURLException e) {

			pushResult.setCode(-10);
			pushResult.setMsg("MalformedURLException");
			pushResult.setStatus(0);
			return pushResult;

		} catch (IOException e) {

			pushResult.setCode(-11);
			pushResult.setMsg("IOException");
			pushResult.setStatus(0);
			return pushResult;
		}
	}
}
