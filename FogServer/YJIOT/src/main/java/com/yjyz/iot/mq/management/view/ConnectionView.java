package com.yjyz.iot.mq.management.view;

import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

import javax.management.Attribute;
import javax.management.AttributeList;
import javax.management.InstanceNotFoundException;
import javax.management.MBeanServerConnection;
import javax.management.ObjectName;
import javax.management.ReflectionException;

public class ConnectionView {
	private String[] attrNames = { "Slow", "Blocked", "Connected", "Active", "RemoteAddress", "ClientId",
			"DispatchQueueSize", "UserName", "Consumers", "Producers", "ActiveTransactionCount",
			"OldestActiveTransactionDuration" };

	Boolean Slow;
	Boolean Blocked;
	Boolean Connected;
	Boolean Active;
	String RemoteAddress;
	String ClientId;
	int DispatchQueueSize;
	String UserName;
	ObjectName[] Consumers;
	ObjectName[] Producers;
	int ActiveTransactionCount;
	Long OldestActiveTransactionDuration;

	MBeanServerConnection connection;
	ObjectName objectName;

	public ConnectionView(MBeanServerConnection connection, ObjectName objectName)
			throws InstanceNotFoundException, ReflectionException, NoSuchMethodException, SecurityException,
			IllegalAccessException, IllegalArgumentException, InvocationTargetException, IOException {
		this.connection = connection;
		this.objectName = objectName;
		getBean(this.objectName);
	}

	public void getBean(ObjectName objectName)
			throws InstanceNotFoundException, ReflectionException, IOException, NoSuchMethodException,
			SecurityException, IllegalAccessException, IllegalArgumentException, InvocationTargetException {
		AttributeList attributeList = connection.getAttributes(objectName, this.attrNames);
		Method setMethod;
		for (Attribute attr : attributeList.asList()) {
			// if(attr.getName().equals("Slow"))
			// {
			// this.setSlow((boolean)attr.getValue());
			// }else if(attr.getName().equals("Blocked"))
			// {
			// this.setBlocked((boolean)attr.getValue());
			// }
			if (attr.getValue() == null) {
				continue;
			}
			if (attr.getValue() instanceof Integer) {
				setMethod = this.getClass().getDeclaredMethod("set" + attr.getName(), int.class);
			} else {
				setMethod = this.getClass().getDeclaredMethod("set" + attr.getName(), attr.getValue().getClass());
			}
			setMethod.invoke(this, attr.getValue());
		}

	}

	public Boolean isSlow() {
		return Slow;
	}

	public void setSlow(Boolean slow) {
		Slow = slow;
	}

	public Boolean isBlocked() {
		return Blocked;
	}

	public void setBlocked(Boolean blocked) {
		Blocked = blocked;
	}

	public Boolean isConnected() {
		return Connected;
	}

	public void setConnected(Boolean connected) {
		Connected = connected;
	}

	public Boolean isActive() {
		return Active;
	}

	public void setActive(Boolean active) {
		Active = active;
	}

	public String getRemoteAddress() {
		return RemoteAddress;
	}

	public void setRemoteAddress(String remoteAddress) {
		RemoteAddress = remoteAddress;
	}

	public String getClientId() {
		return ClientId;
	}

	public void setClientId(String clientId) {
		ClientId = clientId;
	}

	public int getDispatchQueueSize() {
		return DispatchQueueSize;
	}

	public void setDispatchQueueSize(int dispatchQueueSize) {
		DispatchQueueSize = dispatchQueueSize;
	}

	public String getUserName() {
		return UserName;
	}

	public void setUserName(String userName) {
		UserName = userName;
	}

	public ObjectName[] getConsumers() {
		return Consumers;
	}

	public void setConsumers(ObjectName[] consumers) {
		Consumers = consumers;
	}

	public ObjectName[] getProducers() {
		return Producers;
	}

	public void setProducers(ObjectName[] producers) {
		Producers = producers;
	}

	public int getActiveTransactionCount() {
		return ActiveTransactionCount;
	}

	public void setActiveTransactionCount(int activeTransactionCount) {
		ActiveTransactionCount = activeTransactionCount;
	}

	public Long getOldestActiveTransactionDuration() {
		return OldestActiveTransactionDuration;
	}

	public void setOldestActiveTransactionDuration(Long oldestActiveTransactionDuration) {
		OldestActiveTransactionDuration = oldestActiveTransactionDuration;
	}

	public MBeanServerConnection getConnection() {
		return connection;
	}

	public void setConnection(MBeanServerConnection connection) {
		this.connection = connection;
	}

	public ObjectName getObjectName() {
		return objectName;
	}

	public void setObjectName(ObjectName objectName) {
		this.objectName = objectName;
	}

}