#import <UIKit/UIKit.h>
#import <GameKit/GameKit.h>
#import "OnlineSession.h"
#import "OnlineListener.h"

#define kTicTacToeSessionID     @"com.apress.TicTacToe.session"
#define kTicTacToeArchiveKey    @"com.apress.TicTacToe"
#define kBonjourType            @"_tictactoe._tcp."

typedef enum GameStates {
    kGameStateBeginning,
    kGameStateRollingDice,
    kGameStateMyTurn,
    kGameStateOpponentTurn,
    kGameStateInterrupted,
    kGameStateDone
} GameState;



typedef enum BoardSpaces {
    kUpperLeft = 1000, kUpperMiddle, kUpperRight,
    kMiddleLeft, kMiddleMiddle, kMiddleRight,
    kLowerLeft, kLowerMiddle, kLowerRight
} BoardSpace;

typedef enum PlayerPieces {
    kPlayerPieceUndecided,
    kPlayerPieceO,
    kPlayerPieceX
} PlayerPiece;

@class TicTacToePacket;

@interface TicTacToeViewController : UIViewController <GKPeerPickerControllerDelegate, GKSessionDelegate, UIAlertViewDelegate, OnlineSessionDelegate, OnlineListenerDelegate, NSNetServiceDelegate> {
    UIButton    *newGameButton;
    UILabel     *feedbackLabel;
    
    GKSession   *session;
    NSString    *peerID;
    
    GameState   state;
    
    NSInteger   myDieRoll;
    NSInteger   opponentDieRoll;
    
    PlayerPiece piece;
    UIImage     *xPieceImage;
    UIImage     *oPieceImage;
    
    BOOL        dieRollReceived;
    BOOL        dieRollAcknowledged;
    
    // Online Play    
    NSNetService            *netService;
    OnlineSession           *onlineSession;
    OnlineListener          *onlineSessionListener;    
    
}
@property(nonatomic, retain) IBOutlet UIButton *newGameButton;
@property(nonatomic, retain) IBOutlet UILabel *feedbackLabel;

@property(nonatomic, retain) GKSession	 *session;
@property(nonatomic, copy)	 NSString	 *peerID;

@property GameState state;

@property(nonatomic, retain) UIImage *xPieceImage;
@property(nonatomic, retain) UIImage *oPieceImage;

@property (nonatomic, retain) NSNetService       *netService;
@property (nonatomic, retain) OnlineSession      *onlineSession;
@property (nonatomic, retain) OnlineListener     *onlineSessionListener;

- (IBAction)newGameButtonPressed;
- (IBAction)gameSpacePressed:(id)sender;
- (void)resetBoard;
- (void)startNewGame;
- (void)resetDieState;
- (void)sendPacket:(TicTacToePacket *)packet;
- (void)sendDieRoll;
- (void)checkForGameEnd;
- (void)handleReceivedData:(NSData *)data;
- (void)browserCancelled;
@end