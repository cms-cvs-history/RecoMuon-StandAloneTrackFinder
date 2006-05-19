#ifndef RecoMuon_TrackFinder_StandAloneTrajectoryBuilder_H
#define RecoMuon_TrackFinder_StandAloneTrajectoryBuilder_H

/** \class StandAloneTrajectoryBuilder
 *  Concrete class for the STA Muon reco 
 *
 *  $Date: 2006/05/18 08:37:34 $
 *  $Revision: 1.3 $
 *  \author R. Bellan - INFN Torino
 */

#include "RecoMuon/TrackingTools/interface/MuonTrajectoryBuilder.h"

class TrajectorySeed;
class StandAloneMuonRefitter;
class StandAloneMuonBackwardFilter;
class StandAloneMuonSmoother;

#include "FWCore/Framework/interface/ESHandle.h"
#include "Geometry/CommonDetUnit/interface/GlobalTrackingGeometry.h"
#include "MagneticField/Engine/interface/MagneticField.h"

namespace edm {class ParameterSet;}

class StandAloneMuonTrajectoryBuilder : public MuonTrajectoryBuilder{

public:
    
  /** Constructor with Parameter set */
  StandAloneMuonTrajectoryBuilder(const edm::ParameterSet& par);
          
  /** Destructor */
  virtual ~StandAloneMuonTrajectoryBuilder();

  /** Returns a vector of the reconstructed trajectories compatible with
   * the given seed.
   */   
  TrajectoryContainer trajectories(const TrajectorySeed&);

  StandAloneMuonRefitter* refitter() const {return theRefitter;}
  StandAloneMuonBackwardFilter* bwfilter() const {return theBWFilter;}
  StandAloneMuonSmoother* smoother() const {return theSmoother;}

  // Pass the Event Setup to the algo at each event
  virtual void setES(const edm::EventSetup& setup);


 protected:
  
 private:
  
  StandAloneMuonRefitter* theRefitter;
  StandAloneMuonBackwardFilter* theBWFilter;
  StandAloneMuonSmoother* theSmoother;

  double theMaxEta;

  edm::ESHandle<GlobalTrackingGeometry> theTrackingGeometry;
  edm::ESHandle<MagneticField> theMGField;
};
#endif
