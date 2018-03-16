%Aavash Shrestha
%Leul Shiferaw

clear 	
close all
clf
handle_axes= axes('XLim', [-0.4,0.4], 'YLim', [-0.2,0.4], 'ZLim', [0,0.4]);

xlabel('e_1'); 
ylabel('e_2');
zlabel('e_3');

view(-130, 26);
grid on;
axis equal
camlight
axis_length= 0.05;

%Base E
trf_E_axes = hgtransform('Parent', handle_axes);

%Base Link
trf_base_link = make_transform([0, 0, 0], 0, 0, 0, trf_E_axes);
trf_viz_base_link = make_transform([0, 0, 0.0425], 0, 0, 0, trf_base_link);
h(1) = link_box([0.32, 0.26, 0.085], trf_viz_base_link, [0, 0.9, 0.9], [0, 0.9, 0.9], 1.0);

%Base Laser
trf_base_viz_base_laser = make_transform([0, 0, 0], 0, 0, 0);
h(2) = link_cylinder(0.025, 0.07, trf_base_viz_base_laser, [0.2, 0.2, 0.2]);

%Cpu link
trf_viz_cpu_link = make_transform([0, 0, 0.035], 0, 0, 0);
h(3) = link_box([0.19, 0.19, 0.07], trf_viz_cpu_link, [0, 0.7, 0.7]);

%upper_base_link
trf_viz_upper_base_link = make_transform([0, 0, 0.05], 0, 0, 0);
h(4) = link_cylinder(0.085, 0.10, trf_viz_upper_base_link, [0, 0.5, 0.5]);

%torso_link
trf_viz_torso_link = make_transform([0, 0, 0.12], 0, 0, 0);
h(5) = link_cylinder(0.05, 0.24, trf_viz_torso_link, [0.8, 0.8, 0]);

%head_pan_link
trf_viz_head_pan_link = make_transform([0, 0, 0.0225], 0, 0, 0);
h(6) = link_box([0.05, 0.045, 0.045], trf_viz_head_pan_link, [0, 1, 0]);

%head_tilt_link
trf_viz_head_tilt_link = make_transform([0, 0, 0.02], 0, 0, 0);
h(7) = link_box([0.03, 0.038, 0.04], trf_viz_head_tilt_link, [0.1, 0.8, 0.1]);

%neck_link
trf_viz_neck_link = make_transform([0, 0, 0.021], 0, 0, 0);
h(8) = link_box([0.03, 0.05, 0.042], trf_viz_neck_link, [0.1, 0.5, 0.1]);

%head_link
trf_viz_head_link = make_transform([0, 0, 0.025], 0, 0, 0);
h(9) = link_box([0.03, 0.07, 0.11], trf_viz_head_link, [0.9, 0.9, 0.9]);

%eyes_link
%trf_viz_eyes_link = make_transform([0, 0, 0.035], 0, 0, 0);
%h(10) = link_box([0.01, 0.04, 0.01], trf_viz_eyes_link, [0, 0, 0.7]);

%antenna link
trf_viz_antenna_link = make_transform([0, 0, 0.035], 0, 0, 0);
h(11) = link_cylinder(0.002, 0.05, trf_viz_antenna_link, [0.8, 0.8, 0.8]);

%left shoulder link
trf_viz_lshoulder_link = make_transform([0, 0, 0], 0, 0, 0);
h(12) = link_box([0.025, 0.015, 0.05], trf_viz_lshoulder_link, [0, 1, 0]);

%right shoulder link
trf_viz_rshoulder_link = make_transform([0, 0, 0], 0, 0, 0);
h(13) = link_box([0.025, 0.015, 0.05], trf_viz_rshoulder_link, [0, 1, 0]);

%left shoulder forward link
trf_viz_lshoulder_forward_link = make_transform([0, 0, 0], 0, 0, 0);
h(14) = link_box([0.03, 0.05, 0.03], trf_viz_lshoulder_forward_link, [0, 0, 0.9]);

%right shoulder forward link
trf_viz_rshoulder_forward_link = make_transform([0, 0, 0], 0, 0, 0);
h(15) = link_box([0.03, 0.05, 0.03], trf_viz_rshoulder_forward_link, [0, 0, 0.9]);

%left shoulder up link
trf_viz_lshoulder_up_link = make_transform([0, 0, 0], 1.57, 0, 0);
h(16) = link_box([0.03, 0.05, 0.03], trf_viz_lshoulder_up_link, [0, 0, 0.7]);

%right shoulder up link
trf_viz_rshoulder_up_link = make_transform([0, 0, 0], 1.57, 0, 0);
h(17) = link_box([0.03, 0.05, 0.03], trf_viz_rshoulder_up_link, [0, 0, 0.7]);

%left upper arm link
trf_viz_luarm_link = make_transform([0, 0, 0], 0, 0, 0);
h(18) = link_cylinder(0.0075, 0.05, trf_viz_luarm_link, [0.9, 0.9, 0.9]);

%right upper arm link
trf_viz_ruarm_link = make_transform([0, 0, 0], 0, 0, 0);
h(19) = link_cylinder(0.0075, 0.05, trf_viz_ruarm_link, [0.9, 0.9, 0.9]);

%left elbow link
trf_viz_lelbow_link = make_transform([0, 0, 0], 0, 0, 1.57);
h(20) = link_box([0.035, 0.035, 0.05], trf_viz_lelbow_link, [0, 0, 0.7]);

%right elbow link
trf_viz_relbow_link = make_transform([0, 0, 0], 0, 0, 1.57);
h(21) = link_box([0.035, 0.035, 0.05], trf_viz_relbow_link, [0, 0, 0.7]);

%left lower arm link
trf_viz_llarm_link = make_transform([0, 0, 0], 0, 0, 0);
h(22) = link_cylinder(0.0075, 0.11, trf_viz_llarm_link, [0.9, 0.9, 0.9]);

%right lower arm link
trf_viz_rlarm_link = make_transform([0, 0, 0], 0, 0, 0);
h(23) = link_cylinder(0.0075, 0.11, trf_viz_rlarm_link, [0.9, 0.9, 0.9]);

%left wrist link
trf_viz_lwrist_link = make_transform([0, 0, 0], 1.57, 0, 0);
h(24) = link_box([0.03, 0.05, 0.03], trf_viz_lwrist_link, [0, 0, 0.7]);

%right wrist link
trf_viz_rwrist_link = make_transform([0, 0, 0], 1.57, 0, 0);
h(25) = link_box([0.03, 0.05, 0.03], trf_viz_rwrist_link, [0, 0, 0.7]);

%left hand link
trf_viz_lhand_link = make_transform([0, 0, 0], 0, 0, 0);
h(26) = link_box([0.03, 0.01, 0.06], trf_viz_lhand_link, [0.7, 0.7, 0.7]);

%right hand link
trf_viz_rhand_link = make_transform([0, 0, 0], 0, 0, 0);
h(27) = link_box([0.03, 0.01, 0.06], trf_viz_rhand_link, [0.9, 0.9, 0.9]);

%joints--------------------------------
%cpu joint 
trf_cpu_joint = make_transform([0.025, 0, 0.085], 0, 0, 0, trf_base_link);
make_child(trf_cpu_joint, trf_viz_cpu_link);

%base laser joint
trf_base_layer_joint = make_transform([0.18, 0, 0.07], 0, 0, 0, trf_viz_base_link);
make_child(trf_base_layer_joint, trf_base_viz_base_laser);

%upper base joint
trf_ubase_joint = make_transform([0, 0, 0.07], 0, 0, 0, trf_cpu_joint);
make_child(trf_ubase_joint, trf_viz_upper_base_link);

%torso joint
trf_torso_joint_tf = make_transform([0, 0, 0.10], 0, 0, 0, trf_ubase_joint);
trf_torso_joint = make_transform_revolute([0, 0, 1], 0, trf_torso_joint_tf);
make_child(trf_torso_joint, trf_viz_torso_link);

%head pan servo
trf_head_pan_servo = make_transform([0, 0, 0.255], 0, 0, 0, trf_torso_joint);
make_child(trf_head_pan_servo, trf_viz_head_pan_link);

%head pan joint
trf_head_pan_joint_tf = make_transform([0, 0, 0.045], 0, 0, 0, trf_head_pan_servo);
trf_head_pan_joint = make_transform_revolute([0, 0, 1], 0, trf_head_pan_joint_tf);
make_child(trf_head_pan_joint, trf_viz_head_tilt_link);

%head tilt joint
trf_head_tilt_joint_tf = make_transform([0, 0, 0.04], 0, 0, 0, trf_head_pan_joint);
trf_head_tilt_joint = make_transform_revolute([0, 1, 0], 0, trf_head_tilt_joint_tf);
make_child(trf_head_tilt_joint, trf_viz_neck_link);

%neck joint
trf_neck_joint = make_transform([0.05, 0, 0.015], 0, 0, 0, trf_head_tilt_joint);
make_child(trf_neck_joint, trf_viz_head_link);

%eyes joint
%trf_eyes_joint = make_transform([0.02, -0.025, 0.065], 0, 0, 0, trf_neck_joint);
%make_child(trf_eyes_joint, trf_viz_eyes_link);

%antenna joint
trf_antenna_joint = make_transform([0, -0.025, 0.065], 0, 0, 0, trf_neck_joint);
make_child(trf_antenna_joint, trf_viz_antenna_link);

%left shoulder joint
trf_lshoulder_joint = make_transform([0, 0.0555, 0.165], 0, 0, 0, trf_torso_joint);
make_child(trf_lshoulder_joint, trf_viz_lshoulder_link);

%right shoulder joint
trf_rshoulder_joint = make_transform([0, -0.0555, 0.165], 0, 0, 0, trf_torso_joint);
make_child(trf_rshoulder_joint, trf_viz_rshoulder_link);

%left shoulder forward joint
trf_lfshoulder_joint_tf = make_transform([0, 0.025, 0], 0, 0, 0, trf_lshoulder_joint);
trf_lfshoulder_joint = make_transform_revolute([0, 0, 1], 0, trf_lfshoulder_joint_tf);
make_child(trf_lfshoulder_joint, trf_viz_lshoulder_forward_link);

%right shoulder forward joint
trf_rfshoulder_joint_tf = make_transform([0, -0.025, 0], 0, 0, 0, trf_rshoulder_joint);
trf_rfshoulder_joint = make_transform_revolute([0, 0, 1], 0, trf_rfshoulder_joint_tf);
make_child(trf_rfshoulder_joint, trf_viz_rshoulder_forward_link);

%left shoulder up joint
trf_lushoulder_joint_tf = make_transform([0, 0.04, -0.01], 0, -0.707, 0, trf_lfshoulder_joint);
trf_lushoulder_joint = make_transform_revolute([0, 1, 0], 0, trf_lushoulder_joint_tf);
make_child(trf_lushoulder_joint, trf_viz_lshoulder_up_link);

%right shoulder up joint
trf_rushoulder_joint_tf = make_transform([0, -0.04, -0.01], 0, -0.707, 0, trf_rfshoulder_joint);
trf_rushoulder_joint = make_transform_revolute([0, 1, 0], 0, trf_rushoulder_joint_tf);
make_child(trf_rushoulder_joint, trf_viz_rshoulder_up_link);

%left upper arm joint
trf_luarm_joint = make_transform([0, 0, -0.05], 0, 0, 0, trf_lushoulder_joint);
make_child(trf_luarm_joint, trf_viz_luarm_link);

%right upper arm joint
trf_ruarm_joint = make_transform([0, 0, -0.05], 0, 0, 0, trf_rushoulder_joint);
make_child(trf_ruarm_joint, trf_viz_ruarm_link);

%left elbow joint
trf_lelbow_joint_tf = make_transform([-0.005, 0, -0.05], 0, 0, 0, trf_luarm_joint);
trf_lelbow_joint = make_transform_revolute([0, 0 1], 0, trf_lelbow_joint_tf);
make_child(trf_lelbow_joint, trf_viz_lelbow_link);

%right elbow joint
trf_relbow_joint_tf = make_transform([-0.005, 0, -0.05], 0, 0, 0, trf_ruarm_joint);
trf_relbow_joint = make_transform_revolute([0, 0, 1], 0, trf_relbow_joint_tf);
make_child(trf_relbow_joint, trf_viz_relbow_link);

%left lower arm joint
trf_llarm_joint = make_transform([0, 0, -0.08], 0, 0, 0, trf_lelbow_joint);
make_child(trf_llarm_joint, trf_viz_llarm_link);

%right lower arm joint
trf_rlarm_joint = make_transform([0, 0, -0.08], 0, 0, 0, trf_relbow_joint);
make_child(trf_rlarm_joint, trf_viz_rlarm_link);

%left wrist joint
trf_lwrist_joint_tf = make_transform([0, 0, -0.05], 0, 0, 0, trf_llarm_joint);
trf_lwrist_joint = make_transform_revolute([1, 0, 0], 0, trf_lwrist_joint_tf);
make_child(trf_lwrist_joint, trf_viz_lwrist_link);

%right wrist joint
trf_rwrist_joint_tf = make_transform([0, 0, -0.05], 0, 0, 0, trf_rlarm_joint);
trf_rwrist_joint = make_transform_revolute([1, 0, 0], 0, trf_rwrist_joint_tf);
make_child(trf_rwrist_joint, trf_viz_rwrist_link);

%left hand joint
trf_lhand_joint = make_transform([0, 0, -0.055], 0, 0, 0, trf_lwrist_joint);
make_child(trf_lhand_joint, trf_viz_lhand_link);

%right hand joint
trf_rhand_joint = make_transform([0, 0, -0.055], 0, 0, 0, trf_rwrist_joint);
make_child(trf_rhand_joint, trf_viz_rhand_link);

%rotate elbows and head randomly forever

while 1 < 3
    x = rand;
    y = rand;
    z = rand;
    for i= linspace(0, pi/4, 50)     
        set(handle_axes, 'XLim', [-0.4, 0.4], 'YLim', [-0.2, 0.4], 'ZLim', [0, 1]);
        rev = makehgtform('axisrotate', [x, y, z], i);
        set(trf_head_tilt_joint, 'Matrix', rev);

        %set(handle_axes, 'XLim', [-0.4, 0.4], 'YLim', [-0.2, 0.4], 'ZLim', [0, 1]);
        rev = makehgtform('axisrotate', [x, y, z], -i);
        set(trf_lelbow_joint, 'Matrix', rev);
        
        %set(handle_axes, 'XLim', [-0.4, 0.4], 'YLim', [-0.2, 0.4], 'ZLim', [0, 1]);
        rev = makehgtform('axisrotate', [x, y, z], -i);
        set(trf_relbow_joint, 'Matrix', rev);
         
        %set(handle_axes, 'XLim', [-0.4, 0.4], 'YLim', [-0.2, 0.4], 'ZLim', [0, 1]);
        rev = makehgtform('axisrotate', [x, y, z], i);
        set(trf_rushoulder_joint, 'Matrix', rev);

        drawnow;
        %pause(0.005);
    end
end
