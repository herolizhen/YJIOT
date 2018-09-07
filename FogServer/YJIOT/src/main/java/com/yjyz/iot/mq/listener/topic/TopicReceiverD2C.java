package com.yjyz.iot.mq.listener.topic;

import javax.jms.JMSException;
import javax.jms.Message;
import javax.jms.MessageListener;
import javax.jms.TextMessage;

import org.springframework.stereotype.Component;

@Component("topicReceiverD2C")
public class TopicReceiverD2C implements MessageListener {

	@Override
	public void onMessage(Message message) {
		try {
			System.out.println("TopicReceiverD2C接收到消息:" + ((TextMessage) message).getText());
		} catch (JMSException e) {
			e.printStackTrace();
		}
	}
}
