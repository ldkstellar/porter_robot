#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np
from camera_interfaces import Xy  # 커스텀 메시지 import

class CameraPublisher(Node):
    def __init__(self):
        super().__init__('image_publisher')

        # 1. 두 개의 퍼블리셔 생성
        self.publisher_img = self.create_publisher(Image, 'video_frames', 10)
        self.publisher_xy = self.create_publisher(Xy, 'red_center', 10)

        timer_period = 0.1
        self.timer = self.create_timer(timer_period, self.timer_callback)
        # 욜로로 색깔나오잖아그걸로 빨간색으로 추론해서 빨간색 객체찾아서 좌표를 보내는 형태로 만들면 될듯 
        self.cap = cv2.VideoCapture(0)
        self.br = CvBridge()
        self.cx = 0
        self.cy = 0

    def timer_callback(self):
        ret, frame = self.cap.read()

        if ret == True:
            # 2. 빨간색 객체 찾기 및 중심점 계산
            frame, self.cx, self.cy = self.find_and_mark_red_object(frame)

            # 3. 처리된 이미지 표시 (디버깅용)
            cv2.imshow('red', frame)
            cv2.waitKey(1)

            # 4. 이미지 메시지 발행
            self.publisher_img.publish(self.br.cv2_to_imgmsg(frame))

            # 5. 중심점 좌표 메시지 발행
            msg = Xy()
            msg.x = self.cx
            msg.y = self.cy
            self.publisher_xy.publish(msg)

            self.get_logger().info(f'Publishing: ({self.cx}, {self.cy})')

    def find_and_mark_red_object(self, img):
        """빨간색 객체의 중심점을 찾는 함수"""
        cx, cy = 0, 0

        # 1. BGR을 HSV 색상 공간으로 변환
        # HSV는 색상(Hue), 채도(Saturation), 명도(Value)로 구성
        # 색상 기반 검출에 BGR보다 유리
        hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

        # 2. 빨간색 범위 설정 (HSV)
        # H: 0-10 (빨강), S: 120-255 (높은 채도), V: 70-255 (밝기)
        lower_red = np.array([0, 120, 70])
        upper_red = np.array([10, 255, 255])
        mask = cv2.inRange(hsv, lower_red, upper_red)

        # 3. 컨투어(윤곽선) 검출
        # RETR_EXTERNAL: 가장 바깥쪽 윤곽선만 검출
        # CHAIN_APPROX_SIMPLE: 윤곽선 근사화로 메모리 절약
        contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, 
                                       cv2.CHAIN_APPROX_SIMPLE)

        if len(contours) > 0:
            # 4. 가장 큰 컨투어 선택 (면적 기준)
            largest_contour = max(contours, key=cv2.contourArea)

            # 5. 모멘트(Moments)를 이용한 중심점 계산
            # 모멘트: 이미지의 기하학적 특성을 나타내는 값
            M = cv2.moments(largest_contour)

            if M["m00"] != 0:  # 면적이 0이 아닌 경우
                # 중심점 공식: cx = m10/m00, cy = m01/m00
                cx = int(M["m10"] / M["m00"])
                cy = int(M["m01"] / M["m00"])

                # 6. 중심점에 빨간색 원 표시 (시각화)
                cv2.circle(img, (cx, cy), 5, (0, 0, 255), -1)

        return img, cx, cy

def main(args=None):
    """메인 함수"""
    # ROS2 초기화
    rclpy.init(args=args)

    # 노드 생성
    camera_publisher = CameraPublisher()

    # 노드 실행 (무한 루프, Ctrl+C로 종료)
    rclpy.spin(camera_publisher)

    # 노드 종료 처리
    camera_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()