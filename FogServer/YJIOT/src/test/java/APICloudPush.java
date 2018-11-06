
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;

import org.apache.commons.codec.digest.DigestUtils;

import com.alibaba.fastjson.JSON;
import com.yjyz.iot.push.PushResult;

public class APICloudPush {

	@SuppressWarnings("deprecation")
	public static void main(String[] args) {

		while (true) {
			try {

				URL targetUrl = new URL("https://p.apicloud.com/api/push/message");
				String appId = "A6064337161903";
				String appKey = "2CAA1EC3-7FB6-CB0B-8B42-8C7DFDB0820D";
				long t = System.currentTimeMillis();

				appKey = DigestUtils.shaHex(appId + "UZ" + appKey + "UZ" + t) + "." + t;

				//System.out.println(appKey);

				HttpURLConnection httpConnection = (HttpURLConnection) targetUrl.openConnection();
				httpConnection.setDoOutput(true);
				httpConnection.setRequestMethod("POST");
				httpConnection.setRequestProperty("Content-Type", "application/json");
				httpConnection.setRequestProperty("X-APICloud-AppId", appId);
				httpConnection.setRequestProperty("X-APICloud-AppKey", appKey);
				String input = "{\"title\":\"平安宜居\",\"content\":\"test3\",\"type\":2,\"platform\":0,\"userIds\":\"18502251403,13439966787,\"}";

				OutputStream outputStream = httpConnection.getOutputStream();
				outputStream.write(input.getBytes());
				outputStream.flush();

				if (httpConnection.getResponseCode() != 200) {
					throw new RuntimeException("Failed : HTTP error code : " + httpConnection.getResponseCode());
				}

				BufferedReader responseBuffer = new BufferedReader(
						new InputStreamReader((httpConnection.getInputStream())));

				String output;
				String outputString="";
				System.out.println("Output from Server:\n");
				while ((output = responseBuffer.readLine()) != null) {
					System.out.println(output);
					outputString +=output;
				}
				PushResult ret = (PushResult) JSON.parseObject(outputString, PushResult.class);
				System.out.println(ret.getMsg());
				httpConnection.disconnect();

			} catch (MalformedURLException e) {

				e.printStackTrace();

			} catch (IOException e) {

				e.printStackTrace();

			}
			try {
				Thread.sleep(2000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}
