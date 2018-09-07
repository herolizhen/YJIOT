package com.yjyz.iot.example.action;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.atomic.AtomicLong;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

import com.yjyz.iot.example.dto.User;
import com.yjyz.iot.sms.ISendSMS;
import com.yjyz.iot.sms.SMSResult;

@RestController
public class Greeting {

	private static final String template = "Hello, %s!";
	private final AtomicLong counter = new AtomicLong();

	@Autowired
	private ISendSMS sendSMS;

	@RequestMapping(value = "/greeting1", method = RequestMethod.DELETE)
	@ResponseBody
	public User greeting(@RequestParam(value = "name", defaultValue = "World") String name) {
		return new User(counter.incrementAndGet(), "greet", 22);
	}

	@RequestMapping(value = "/greeting2")
	public String Greeting2(@RequestParam(value = "name", defaultValue = "meiyou") String name) {
		return name;
	}

	@RequestMapping("/greeting3")
	public List<User> greeting3(@RequestParam(value = "name", defaultValue = "World") String name) {
		List<User> list = new ArrayList<User>();
		list.add(new User(counter.incrementAndGet(), String.format(template, name), 23));
		list.add(new User(counter.incrementAndGet(), String.format(template, name), 24));
		return list;
	}

	@RequestMapping(value = "/sms", method = RequestMethod.GET)
	public User sms(@RequestParam(value = "tel", defaultValue = "13439966787") String tel) {
		SMSResult rst = this.sendSMS.sendVerCode(tel, "8888");
		return new User(counter.incrementAndGet(), rst.getFactory() + rst.getCode() + rst.getMessage(), 22);
	}
}