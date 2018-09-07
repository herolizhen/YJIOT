package com;


import com.yjyz.iot.webservice.IM26WebService;

public class ClientForCXF {
	public static IM26WebService getInterFace() {
		//JaxWsProxyFactoryBean factoryBean = new JaxWsProxyFactoryBean();
		//factoryBean.setServiceClass(IM26WebService.class);
		//factoryBean.setAddress("http://localhost:8080/WS/M26");
		//return (IM26WebService) factoryBean.create();
		return null;
	}

	public static void main(String[] args) {
		IM26WebService myWebService = getInterFace();
		System.out.println("client: " + myWebService.add(1, 3));
	}
}
