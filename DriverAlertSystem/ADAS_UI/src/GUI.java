import java.net.URL;
import java.nio.file.Paths;
import java.util.Optional;

import javafx.application.Application;
import javafx.beans.binding.Bindings;
import javafx.beans.property.DoubleProperty;
import javafx.geometry.HPos;
import javafx.event.*;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.CheckMenuItem;
//import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.scene.control.TextInputDialog;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
//import javafx.scene.control.TextInputDialog;
//import javafx.scene.image.Image;
//import javafx.scene.image.ImageView;
import javafx.scene.control.Menu;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.ColumnConstraints;
import javafx.scene.layout.GridPane;
//import javafx.scene.layout.Priority;
import javafx.scene.layout.RowConstraints;
import javafx.scene.layout.StackPane;
import javafx.scene.media.AudioClip;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import javafx.scene.media.MediaView;
import javafx.scene.paint.Color;
import javafx.scene.paint.Paint;
//import javafx.scene.text.Font;
import javafx.stage.Stage;
//import javafx.stage.Popup;

public class GUI extends Application implements Runnable{

	boolean fileFound;
//	URL audio = getClass().getResource("warning-signal.wav");
//	AudioClip alertSound = new AudioClip(GUI.class.getResource("warning-signal.wav").toString());
//
//	AudioClip alertSound = new AudioClip((audio).toString());
//	AudioClip laneAlertSound;
//	AudioClip stopSignAlertSound;
//	AudioClip trafficLghtAlertSound;
//	AudioClip alertSound;
//	final AudioClip alertSound = new AudioClip(GUI.class.getResource("warning-signal.wav").toString());
	Media media;
	MediaPlayer mediaPlayer;
	MediaView mediaView;
	//unsigned int number = 0;

	Color textColor = Color.BLACK;

	// menus
	MenuBar menu = new MenuBar();
	Label statusBar = new Label("System status goes here!");
	Menu system = new Menu("System");
	MenuItem close = new MenuItem("Close");
	Menu options = new Menu("Options");
	Menu view = new Menu("View");
	CheckMenuItem nightView;

	//labels
	Label leftLane = new Label("Left Lane");
	Label rightLane = new Label("Right Lane");
	Label approachingVehicle = new Label("Vehicle Ahead");
	Label pedestrian = new Label("Pedestrian");
	Label stopSign = new Label("Stop Sign");
	Label trafficSignal = new Label("Traffic Light");
	
	GridPane alertWindow = new GridPane();
	BorderPane root;
	Scene primaryScene;



	// path to file must be specific format
	private static final String MEDIA_LOCATION = Paths.get("intlvid.mp4").toUri().toString();

	public static void main(String[] args) {
		
		DataReceiver dr = new DataReceiver();
		launch(args);
	}

	@Override
	public void start(Stage primaryStage) throws Exception {

		do{
			//get player names
			TextInputDialog dialog1 = new TextInputDialog("Source URL");
			dialog1.setTitle("ADAS video stream source");
			dialog1.setHeaderText("Enter source URL (Cancel for default)");
			dialog1.setContentText("Video source address:");

			// get the response
			String mediaURL = MEDIA_LOCATION;
			Optional<String> result = dialog1.showAndWait();
			if (result.isPresent()){
				System.out.println("Player 1: " + result.get());
				mediaURL = result.get();
			}
			result.ifPresent(url -> System.out.println("Media location: " + url));

			close.setOnAction(actionEvent -> System.exit(0));

			system.getItems().addAll(close);

			nightView = new CheckMenuItem("Night View");
			//view
			view.getItems().add(nightView);
			menu.getMenus().addAll(system, options, view);

			// open video stream
			//		do{
			try {
				fileFound = false;
				// video window
				// media
				//media = new Media("http://download.oracle.com/otndocs/products/javafx/oow2010-2.flv"); //string to media file
				//media = new Media("http://127.0.0.1:4444/Guardians_of_the_Galaxy.mp4");
				media = new Media(mediaURL); //string to media file
				fileFound = true;
				// media player
				mediaPlayer = new MediaPlayer(media);
				// media view
				mediaView = new MediaView(mediaPlayer);
			} catch (Exception e) {
				System.out.println("Failed to load video file");
				fileFound = false;
				System.out.println(e);
			}
		}while(!fileFound);

		DoubleProperty mvw = mediaView.fitWidthProperty();
		DoubleProperty mvh = mediaView.fitHeightProperty();
		mvw.bind(Bindings.selectDouble(mediaView.sceneProperty(), "width"));
		mvh.bind(Bindings.selectDouble(mediaView.sceneProperty(), "height"));
		mediaView.setPreserveRatio(true);

		// alert window
		alertWindow = new GridPane();
		//alertWindow.setHalignment(alertWindow, HPos.CENTER);
		alertWindow.setGridLinesVisible(true);
		//Label leftLane = new Label("Left Lane");
		alertWindow.setHalignment(leftLane, HPos.CENTER);
		leftLane.setScaleX(2);
		leftLane.setScaleY(2);
		//Label rightLane = new Label("Right Lane");
		alertWindow.setHalignment(rightLane, HPos.CENTER);
		rightLane.setScaleX(2);
		rightLane.setScaleY(2);
		//Label approachingVehicle = new Label("Vehicle Ahead");
		alertWindow.setHalignment(approachingVehicle, HPos.CENTER);
		approachingVehicle.setScaleX(2);
		approachingVehicle.setScaleY(2);
		//Label pedestrian = new Label("Pedestrian");
		alertWindow.setHalignment(pedestrian, HPos.CENTER);
		pedestrian.setScaleX(2);
		pedestrian.setScaleY(2);
		//Label stopSign = new Label("Stop Sign");
		alertWindow.setHalignment(stopSign, HPos.CENTER);
		stopSign.setScaleX(2);
		stopSign.setScaleY(2);
		//Label trafficSignal = new Label("Traffic Light");
		alertWindow.setHalignment(trafficSignal, HPos.CENTER);
		trafficSignal.setScaleX(2);
		trafficSignal.setScaleY(2);

		alertWindow.add(leftLane, 0,0);
		alertWindow.add(rightLane, 1, 0);
		alertWindow.add(approachingVehicle, 0, 1);
		alertWindow.add(pedestrian, 1, 1);
		alertWindow.add(stopSign, 0, 2);
		alertWindow.add(trafficSignal, 1, 2);

		RowConstraints rows = new RowConstraints();
		rows.setPercentHeight(30);
		alertWindow.getRowConstraints().addAll(rows, rows, rows);

		ColumnConstraints column1 = new ColumnConstraints();
		column1.setPercentWidth(50);
		ColumnConstraints column2 = new ColumnConstraints();
		column2.setPercentWidth(50);
		alertWindow.getColumnConstraints().addAll(column1, column2);

		GridPane splitWindow = new GridPane();
		//splitWindow.setGridLinesVisible(true);
		StackPane mediaWindow = new StackPane();
		mediaWindow.getChildren().add(mediaView);

		splitWindow.add(mediaWindow, 0, 0);
		splitWindow.add(alertWindow, 1, 0);
		ColumnConstraints splitWindowColumn1 = new ColumnConstraints();
		ColumnConstraints splitWindowColumn2 = new ColumnConstraints();

		splitWindowColumn1.setPercentWidth(50);
		splitWindowColumn2.setPercentWidth(50);

		splitWindow.getColumnConstraints().add(splitWindowColumn1);
		splitWindow.getColumnConstraints().add(splitWindowColumn2);


		root = new BorderPane();
		root.setTop(menu);
		root.setCenter(splitWindow);
		root.setBottom(statusBar);
		root.setVisible(true);

		primaryScene = new Scene(root, 1070, 300);

		primaryStage.setTitle("ERAU EcoCAR3 ADAS");
		primaryStage.setScene(primaryScene);
		primaryStage.setResizable(true);
		primaryStage.show();

		mediaPlayer.setMute(true);
		mediaPlayer.play();

		primaryScene.setOnKeyPressed(new EventHandler<KeyEvent>() {
			@Override
			public void handle(KeyEvent event) {
				Thread audioThread = new Thread();
				if (event.getCode()==KeyCode.Q) {
					leftLane.setTextFill(Color.RED);
					//audioThread.run(alertSound);

				} else if (event.getCode() == KeyCode.W) {
					rightLane.setTextFill(Color.RED);
					//audioThread.run(alertSound);


				} else if (event.getCode() == KeyCode.A) {
					approachingVehicle.setTextFill(Color.RED);
					//audioThread.run(alertSound);


				} else if (event.getCode() == KeyCode.S) {
					pedestrian.setTextFill(Color.RED);
					//audioThread.run(alertSound);


				}else if (event.getCode() == KeyCode.Z) {
					stopSign.setTextFill(Color.RED);
					//audioThread.run(alertSound);


				}else if (event.getCode() == KeyCode.X) {
					trafficSignal.setTextFill(Color.RED);
					//audioThread.run(alertSound);

				}

			}
		});

		primaryScene.setOnKeyReleased(new EventHandler<KeyEvent>() {
			@Override
			public void handle(KeyEvent event) {
				if (!nightView.isSelected()){
					textColor = Color.BLACK;
					setColors();
				}else{
					textColor = Color.GREEN;
					setColors();
				}
				if (event.getCode() == KeyCode.Q){
					leftLane.setTextFill(textColor);
				}else if (event.getCode() == KeyCode.W){
					rightLane.setTextFill(textColor);
				}else if (event.getCode() == KeyCode.A){	
					approachingVehicle.setTextFill(textColor);
				}else if (event.getCode() == KeyCode.S){
					pedestrian.setTextFill(textColor);
				}else if (event.getCode() == KeyCode.Z){
					stopSign.setTextFill(textColor);
				}else if (event.getCode() == KeyCode.X){
					trafficSignal.setTextFill(textColor);
				}
			}
		});

		// deal with day/night modes
		nightView.setOnAction(new EventHandler<ActionEvent>(){

			@Override
			public void handle(ActionEvent event) {
				if (!nightView.isSelected()){
					textColor = Color.BLACK;
					setColors();
				}else{
					textColor = Color.GREEN;
					setColors();
				}
				if (nightView.isSelected()){
					System.out.println("Night mode activated");
					//set dark background
					BackgroundFill fill = new BackgroundFill(Color.BLACK, null, null);
					Background background = new Background(fill);
					alertWindow.setBackground(background);
					//set light text

				}else if (!nightView.isSelected()){
					System.out.println("Night mode disabled");
					BackgroundFill fill = new BackgroundFill(null, null, null);
					Background background = new Background(fill);
					alertWindow.setBackground(background);
					//set light background
					//set dark text
				}
			}

		});

	}

	public void setColors(){
		//set Menu colors

		//set label colors
		leftLane.setTextFill(textColor);
		rightLane.setTextFill(textColor);
		approachingVehicle.setTextFill(textColor);
		pedestrian.setTextFill(textColor);
		stopSign.setTextFill(textColor);
		trafficSignal.setTextFill(textColor);
	}

	public void run(AudioClip alertSound) {

		alertSound.play();
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub

	}
	
	public void setStatus(String status){
		this.statusBar.setText(status);
		root.setBottom(this.statusBar);
	}
}
